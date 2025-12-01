#ifndef LOOKUP_H
#define LOOKUP_H

#include "Document.hpp"
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>



// struct holding an occurence of a single word in documents.
struct Entry {
  Word word; // the word itself
  std::set<DocumentName> documentNames; // a set of all documents containing that word
};


// type for resulting documents
typedef std::vector<DocumentName> Results;


// document collection as a vector.
typedef std::vector<Entry> VectorCollection;

// add the document to the collection.
void add_document(const Document & doc, VectorCollection & collection);

// return all the documents (in sorted order) that contain the given word (in lowercase).
Results lookup_word(const Word & word, const VectorCollection & collection);



// document collection as a list.
typedef std::list<Entry> ListCollection;
void add_document(const Document & doc, ListCollection & collection);
Results lookup_word(const Word & word, const ListCollection & collection);



// document collection as a map: keys are words, values are entries.
typedef std::map<Word, Entry> MapCollection;
void add_document(const Document & doc, MapCollection & collection);
Results lookup_word(const Word & word, const MapCollection & collection);



#endif
