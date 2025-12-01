#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <vector>


// string typedefs to help clarify what strings represent
typedef std::string DocumentName;
typedef std::string Word;

// struct holding a document name, and the words in that document split into a vector of words in the order they were in the document, converted to lowercase.
struct Document {
  DocumentName documentName;
  std::vector<Word> words;
};



// return a copy the string in all lowercase.
std::string tolower(const std::string & str);

// try to read in all the documents in documentNames using read_document.
// if a document can be read, it is added to the end of documents.
void read_documents(const std::vector<DocumentName> & documentNames, std::vector<Document> & documents);

// try to read in a single document from a file.
// the file to read from is "doc/" + documentName + ".txt".
// if it can be read, document is filled in with all the words in the document, and true is returned.
// if it can't be read, false is returned.
// a document is read line-by-line until an error reading a line.
// when reading a document, if a line starts with a #, it is considered a comment and ignored.
// otherwise, whitespace separated words are read from the line (until error), converted to lowercase, and stored in the document in the order they are in the file.
bool read_document(const DocumentName & documentName, Document & document);

// print information about the document to stdout.
// the first line is "document: " followed by the document name.
// then, each of the words is printed on thier own line as "word: " followed by the word.
void display_document(const Document & document);

#endif
