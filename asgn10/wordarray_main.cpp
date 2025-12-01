#include "WordArray.hpp"
#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;



void
printWordArray(const WordArray & wa)
{
  cout << wa.m_numWords << " ";
  cout << wa.m_maxWords << " ";
  for (size_t ii = 0; ii < wa.m_maxWords; ++ ii) {
    cout << (wa.m_array[ii] ? 'O' : '/');
  }
  cout << endl;
}

// allocates temporary buffer just big enough to hold string
class StrdupTmp {
public:
  StrdupTmp(const string & str) {
    m_buf = new char[str.size() + 1];
    str.copy(m_buf, str.size());
    m_buf[str.size()] = '\0';
  }
  ~StrdupTmp() {
    delete [] m_buf;
  }
  operator const char *() const {
    return m_buf;
  }
private:
  char *m_buf;
};

int main()
{
  map<string, WordArray *> ws;

  string line;

  while (getline(cin, line)) {
    stringstream sstr(line + '\n');

    string name;
    sstr >> name;

    WordArray * wa = ws[name];

    string input;
    sstr >> input;

    if (input == "new-size") {
      if (wa) {
	cout << "Already exists." << endl;
	continue;
      }
      
      size_t size;
      sstr >> size;
      
      if (!sstr || size > 20) {
	cout << "Invalid size." << endl;
	continue;
      }
      
      wa = new WordArray(size);
      ws[name] = wa;

      cout << "Allocated." << endl;
    } else if (input == "new-string") {
      if (wa) {
	cout << "Already exists." << endl;
	continue;
      }
      
      sstr.ignore(1);
      if (!getline(sstr, input)) {
	continue;
      }
      
      wa = new WordArray(StrdupTmp(input));
      ws[name] = wa;

      cout << "Allocated." << endl;
    } else if (input == "append") {
      if (!wa) {
	cout << "No array." << endl;
	continue;
      }
      
      sstr >> input;
      WordArray * wo = ws[input];

      if (!wo) {
	cout << "No other array." << endl;
	continue;
      }

      wa->append(*wo);
      
      cout << "Appended." << endl;
    } else if (input == "print") {
      if (!wa) {
	cout << "No array." << endl;
	continue;
      }

      wa->print(cout);
    } else if (input == "meta") {
      if (!wa) {
	cout << "No array." << endl;
	continue;
      }

      printWordArray(*wa);
    } else if (input == "findFirst") {
      if (!wa) {
	cout << "No array." << endl;
	continue;
      }

      sstr >> input;
      
      const char * loc = wa->findFirst(StrdupTmp(input));
      cout << (loc ? loc : "Not found.") << endl;
    } else if (input == "removeAll") {
      if (!wa) {
	cout << "No array." << endl;
	continue;
      }

      sstr >> input;

      size_t result = wa->removeAll(StrdupTmp(input));
      cout << result << endl;
    } else if (input == "delete") {
      if (!wa) {
	cout << "No array." << endl;
	continue;
      }

      delete wa;
      wa = nullptr;
      ws[name] = nullptr;

      cout << "Deallocated." << endl;
    } else {
      cout << "Unrecognized command." << endl;
    }
  }

  for (auto & elem: ws) {
    delete elem.second;
  }
}
