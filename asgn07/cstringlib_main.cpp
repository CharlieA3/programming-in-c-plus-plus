#include "cstringlib.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const char *checkstring(const char *str) {
  return str ? str : "NULL";
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

int main() {
  const size_t STRBUFSIZE = 21;
  char strbuf[STRBUFSIZE] = { '\0', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' };

  string line;
  while (getline(cin, line)) {
    stringstream sstr(line + '\n');

    string command;
    sstr >> command;
    sstr.ignore(1);

    if (command == "print") {
      cout << strbuf << endl;
    } else if (command == "printall") {
      for (char c: strbuf) {
	cout << ((c < 32 || c > 126) ? '_' : c);
      }
      cout << endl;
    } else if (command == "strlen") {
      cout << cstring::strlen(strbuf) << endl;
    } else if (command == "strncpy") {
      string input;
      if (getline(sstr, input)) {
	char * res = cstring::strncpy(strbuf, StrdupTmp(input), STRBUFSIZE - 1);
	strbuf[STRBUFSIZE - 1] = '\0';
	cout << checkstring(res) << endl;
      }
    } else if (command == "strncat") {
      string input;
      if (getline(sstr, input)) {
	char * res = cstring::strncat(strbuf, StrdupTmp(input), STRBUFSIZE - cstring::strlen(strbuf) - 1);
	cout << checkstring(res) << endl;
      }
    } else if (command == "strcmp") {
      string input;
      if (getline(sstr, input)) {
	int res = cstring::strcmp(strbuf, StrdupTmp(input));
	if (res < 0) {
	  cout << "<0" << endl;
	} else if (res > 0) {
	  cout << ">0" << endl;
	} else {
	  cout << "=0" << endl;
	}
      }
    } else if (command == "strchr") {
      char chr;
      if (sstr >> chr) {
	cout << checkstring(cstring::strchr(strbuf, chr)) << endl;
      }
    } else if (command == "strrchr") {
      char chr;
      if (sstr >> chr) {
	cout << checkstring(cstring::strrchr(strbuf, chr)) << endl;
      }
    } else if (command == "strstr") {
      string input;
      if (getline(sstr, input)) {
	cout << checkstring(cstring::strstr(strbuf, StrdupTmp(input))) << endl;
      }
    } else if (command == "strtok-str") {
      string input;
      if (getline(sstr, input)) {
	cout << checkstring(cstring::strtok(strbuf, StrdupTmp(input))) << endl;
      }
    } else if (command == "strtok-null") {
      string input;
      if (getline(sstr, input)) {
	cout << checkstring(cstring::strtok(nullptr, StrdupTmp(input))) << endl;
      }
    } else {
      cout << "Unrecognized command." << endl;
    }
  }
}
