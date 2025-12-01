#include "Lookup.hpp"
using namespace std;

void add_document(const Document &doc, VectorCollection &collection)
{
  // TODO: go through each word in the document
  // TODO: see if the word already has an entry in the collection
  // TODO: if it is, update its entry to include the current document name
  // TODO: otherwise, make a new entry for the word (and current document name)
  for (vector<Word>::const_iterator w_iter = doc.words.begin(); w_iter != doc.words.end(); w_iter++)
  {
    bool found = false;
    for (VectorCollection::iterator col_iter = collection.begin(); col_iter != collection.end(); col_iter++)
    {
      if (*w_iter == col_iter->word)
      {
        col_iter->documentNames.insert(doc.documentName);
        found = true;
        break;
      }
    }
    if (!found)
    {
      Entry new_entry;
      new_entry.word = *w_iter;
      new_entry.documentNames.insert(doc.documentName);

      collection.push_back(new_entry);
    }
  }
}

Results lookup_word(const Word &word, const VectorCollection &collection)
{
  Results ret;
  // TODO: see if the word has an entry in the collection
  // TODO: if so, add all of the entry's document names to the results
  for (VectorCollection::const_iterator iter = collection.begin(); iter != collection.end(); iter++)
  {
    if (tolower(word) == iter->word)
    {
      for (set<DocumentName>::const_iterator doc_iter = iter->documentNames.begin(); doc_iter != iter->documentNames.end(); doc_iter++)
      {
        ret.push_back(*doc_iter);
      }
    }
  }
  return ret;
}

void add_document(const Document &doc, ListCollection &collection)
{
  for (vector<Word>::const_iterator w_iter = doc.words.begin(); w_iter != doc.words.end(); w_iter++)
  {
    bool found = false;
    for (ListCollection::iterator l_iter = collection.begin(); l_iter != collection.end(); l_iter++)
    {
      if (*w_iter == l_iter->word)
      {
        l_iter->documentNames.insert(doc.documentName);
        found = true;
        break;
      }
    }
    if (!found)
    {
      Entry new_entry;
      new_entry.word = *w_iter;
      new_entry.documentNames.insert(doc.documentName);

      collection.push_back(new_entry);
    }
  }
}

Results lookup_word(const Word &word, const ListCollection &collection)
{
  Results ret;

  for (ListCollection::const_iterator iter = collection.begin(); iter != collection.end(); iter++)
  {
    if (tolower(word) == iter->word)
    {
      for (set<DocumentName>::const_iterator doc_iter = iter->documentNames.begin(); doc_iter != iter->documentNames.end(); doc_iter++)
      {
        ret.push_back(*doc_iter);
      }
    }
  }
  return ret;
}

void add_document(const Document &doc, MapCollection &collection)
{
  for (vector<Word>::const_iterator w_iter = doc.words.begin(); w_iter != doc.words.end(); w_iter++)
  {
    // I get it now
    MapCollection::iterator m_iter = collection.find(*w_iter);
    if (m_iter != collection.end())
    {
      m_iter->second.documentNames.insert(doc.documentName);
    }
    else
    {
      Entry new_entry;
      new_entry.word = *w_iter;
      new_entry.documentNames.insert(doc.documentName);

      collection[*w_iter] = new_entry;
    }
  }
}

Results lookup_word(const Word &word, const MapCollection &collection)
{
  Results ret;

  // TODO: see if the word has an entry in the collection
  // TODO: if so, add all of the entry's document names to the results
  MapCollection::const_iterator m_iter = collection.find(tolower(word));
  if (m_iter != collection.end())
  {
    for (set<DocumentName>::const_iterator doc_iter = m_iter->second.documentNames.begin();
         doc_iter != m_iter->second.documentNames.end(); doc_iter++)
    {
      ret.push_back(*doc_iter);
    }
  }
  return ret;
}
