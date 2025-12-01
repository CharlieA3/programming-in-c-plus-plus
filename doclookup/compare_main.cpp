#include "Document.hpp"
#include "Lookup.hpp"
#include <string>
using namespace std;

// TODO: change these as needed
const DocumentName docname = "primes_large";
const int iterations = 1000;
// const DocumentName docname = "primes_large";
// const int iterations = 1;
const Word missing_word = "notthere";

void use_vector(const Document &doc)
{
  for (int i = 0; i < iterations; ++i)
  {
    VectorCollection c;
    add_document(doc, c);
    lookup_word(missing_word, c);
  }
}

void use_list(const Document &doc)
{
  for (int i = 0; i < iterations; ++i)
  {
    ListCollection c;
    add_document(doc, c);
    lookup_word(missing_word, c);
  }
}

void use_map(const Document &doc)
{
  for (int i = 0; i < iterations; ++i)
  {
    MapCollection c;
    add_document(doc, c);
    lookup_word(missing_word, c);
  }
}

int main()
{
  Document document;
  read_document(docname, document);

  use_vector(document);
  use_list(document);
  use_map(document);
}
