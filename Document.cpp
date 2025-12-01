#include "Document.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

string tolower(const string &str)
{
  string converted;
  // since I am using an iterator which is just a pointer, it can be dereferenced to get the char
  for (string::const_iterator iter = str.begin(); iter != str.end(); iter++)
  {
    char c = *iter;
    converted += std::tolower(c);
  }

  return converted;
}

void read_documents(const vector<DocumentName> &documentNames, vector<Document> &documents)
{
  // iterate over the document names vector
  for (vector<DocumentName>::const_iterator iter = documentNames.begin(); iter != documentNames.end(); iter++)
  {
    Document doc;
    if (read_document(*iter, doc))
    {
      documents.push_back(doc);
    }
  }
}

bool read_document(const DocumentName &documentName, Document &document)
{
  document.documentName = documentName;
  string read_in_from = "doc/" + document.documentName + ".txt";
  const char *file_string = read_in_from.c_str();

  ifstream file(file_string);

  if (!file.is_open())
  {
    return false;
  }

  string line;
  while (getline(file, line))
  {
    if (line[0] == '#')
    {
      continue;
    }
    else
    {
      stringstream ss(line);
      string w;
      while (ss >> w)
      {
        document.words.push_back(tolower(w));
      }
    }
  }
  // we will only get here if everything finished
  return true;
}

void display_document(const Document &document)
{
  cout << "document: " << document.documentName << endl;

  for (vector<Word>::const_iterator iter = document.words.begin(); iter != document.words.end(); iter++)
  {
    cout << "word: " << *iter << endl;
  }
}
