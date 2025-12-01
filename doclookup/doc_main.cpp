#include "Document.hpp"
#include "Lookup.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;



void print_results(const Results & results) {
  cout << "Found in:";
  if (results.empty()) {
    cout << " NONE" << endl;
  } else {
    for (size_t ii = 0; ii < results.size(); ++ ii) {
      cout << " " << results[ii];
    }
    cout << endl;
  }
}

int main() {
  vector<DocumentName> documentNames;
  documentNames.push_back("color");
  documentNames.push_back("fruit");
  documentNames.push_back("test");
  documentNames.push_back("mammal");
  documentNames.push_back("duplicate");
  documentNames.push_back("missing");

  vector<Document> documents;
  read_documents(documentNames, documents);

  VectorCollection vectorCollection;
  ListCollection listCollection;
  MapCollection mapCollection;

  for (size_t ii = 0; ii < documents.size(); ++ ii) {
    add_document(documents[ii], vectorCollection);
    add_document(documents[ii], listCollection);
    add_document(documents[ii], mapCollection);
  }

  string line;
  while (getline(cin, line)) {
    stringstream sstr(line);

    string command;
    sstr >> command;

    if (command == "list") {
      for (size_t ii = 0; ii < documents.size(); ++ ii) {
	cout << "document: " << documents[ii].documentName << endl;
      }
    } else if (command == "print") {
      string input;
      if (sstr >> input) {
	for (size_t ii = 0; ii < documents.size(); ++ ii) {
	  if (documents[ii].documentName == input) {
	    display_document(documents[ii]);
	    break;
	  }
	}
      }
    } else if (command == "lookup-v") {
      string input;
      if (sstr >> input) {
	print_results(lookup_word(input, vectorCollection));
      }
    } else if (command == "lookup-l") {
      string input;
      if (sstr >> input) {
	print_results(lookup_word(input, listCollection));
      }
    } else if (command == "lookup-m") {
      string input;
      if (sstr >> input) {
	print_results(lookup_word(input, mapCollection));
      }
    } else {
      cout << "Unrecognized command." << endl;
    }
  }
}
