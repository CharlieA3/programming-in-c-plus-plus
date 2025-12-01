#include "WordArray.hpp"
#include <cstring>
using namespace std;

char *my_strdup(const char *what)
{
  if (what == nullptr)
    return nullptr;

  char *new_s = new char[strlen(what) + 1];

  strcpy(new_s, what);

  return new_s;
}

size_t WordArray::countWords(char *words)
{
  size_t i = 0;
  char *token;

  token = strtok(words, " ");
  while (token != NULL)
  {
    token = strtok(NULL, " ");
    i++;
  }
  return i;
}

void WordArray::initialize(size_t maxWords)
{
  m_array = new char *[maxWords];
  for (size_t i = 0; i < maxWords; i++)
  {
    m_array[i] = nullptr;
  }
}

void WordArray::appendWords(char *words)
{
  (void)words; // TODO
}

void WordArray::appendArray(char const *const *array, size_t num)
{
  (void)array;
  (void)num; // TODO
}

void WordArray::increaseMaxWords(size_t newMax)
{
  (void)newMax; // TODO
}

WordArray::WordArray(size_t maxWords)
{
  m_numWords = 0;
  m_maxWords = maxWords;

  initialize(maxWords);
}

WordArray::WordArray(const char *words)
{
  if (words == nullptr || words[0] == '\0')
  {
    m_numWords = 0;
    m_maxWords = 0;
    m_array = nullptr;
    return;
  }
  char *words_count = new char[strlen(words) + 1];
  char *words_input = new char[strlen(words) + 1];
  strcpy(words_count, words);
  strcpy(words_input, words);

  size_t word_count = countWords(words_count);
  delete[] words_count;

  // filling to the max
  m_numWords = word_count;
  m_maxWords = word_count;

  char *token = strtok(words_input, " ");

  // create new array and new words for each index in that array, copying them over properly
  initialize(m_maxWords);
  size_t i = 0;
  while (token != nullptr)
  {

    m_array[i] = new char[strlen(token) + 1];
    strcpy(m_array[i], token);
    i++;
    token = strtok(nullptr, " ");
  }

  // this should do a cascading delete to get rid of all characters
  delete[] words_input;
}

WordArray::~WordArray()
{
  for (size_t i = 0; i < m_maxWords; i++)
  {
    delete[] m_array[i];
  }
  delete[] m_array;
}

std::ostream &WordArray::print(std::ostream &os) const
{
  for (size_t i = 0; i < m_numWords; i++)
  {
    os.write(m_array[i], strlen(m_array[i]));
    if (i != m_numWords - 1)
    {
      os << " ";
    }
  }

  os << "\n";

  return os;
}

const char *WordArray::findFirst(const char *word) const
{
  for (size_t i = 0; i < m_numWords; i++)
  {
    if (strcmp(word, m_array[i]) == 0)
    {
      return m_array[i];
    }
  }
  // if nothing is found when searching the array, return nullptr
  return nullptr;
}

// this is a two pointer problem
size_t WordArray::removeAll(const char *word)
{
  size_t dst = 0;
  size_t words_removed = 0;

  for (size_t i = 0; i < m_numWords; i++)
  {
    if (strcmp(m_array[i], word) == 0)
    {
      delete[] m_array[i];
      words_removed++;
    }
    else
    {
      m_array[dst] = m_array[i];
      dst++;
    }
  }

  m_numWords = dst;

  for (size_t i = m_numWords; i < m_maxWords; i++)
  {
    m_array[i] = nullptr;
  }

  return words_removed;
}

void WordArray::append(const WordArray &src)
{
  if (m_numWords + src.m_numWords > m_maxWords)
  {
    size_t max = m_numWords + src.m_numWords;

    char **array_n = new char *[max];

    for (size_t i = 0; i < m_numWords; i++)
    {
      array_n[i] = my_strdup(m_array[i]);
    }

    for (size_t i = 0; i < src.m_numWords; i++)
    {
      array_n[m_numWords + i] = my_strdup(src.m_array[i]);
    }

    for (size_t i = 0; i < m_numWords; i++)
    {
      delete[] m_array[i];
    }

    delete[] m_array;

    m_array = array_n;
    m_maxWords = max;
    m_numWords += src.m_numWords;
  }
  else
  {
    for (size_t i = 0; i < src.m_numWords; i++)
    {
      m_array[m_numWords + i] = my_strdup(src.m_array[i]);
    }
    m_numWords += src.m_numWords;
  }
}