#ifndef WORDARRAY_HPP
#define WORDARRAY_HPP



#include <iostream>



// WordArray class
class WordArray {
private:
  size_t m_numWords; // Number of words currently in the array
  size_t m_maxWords; // The total size allocated to the array
  char ** m_array;   // The dynamic array storing the words

  // for testing and debugging
  friend void printWordArray(const WordArray & wa);

  // prevent copying
  WordArray(const WordArray &) = delete;
  WordArray & operator=(const WordArray &) = delete;

  // potentially useful helper functions
  // these don't have to be implemented but can be if helpful
  static size_t countWords(char * words); // count the number of words in a C-string (note: may change the C-string passed in)
  void initialize(size_t maxWords); // initialize empty data structure to hold maxWords
  void appendWords(char * words); // append the words from a C-string (note: may change the C-string passed in)
  void appendArray(char const * const * array, size_t num); // append copies of words from an existing array
  void increaseMaxWords(size_t newMax); // reallocate array and move existing words

public:

  /* Takes the maxWords of the array and initializes the WordArray with
   * the given maxWords without assigning any words, sets numWords to
   * zero. A zero size array is okay.
   */
  explicit WordArray(size_t maxWords);

  /* Constructor taking a character array with words separated by any
   * number of spaces, for example:
   *
   * "charmeleon mewtwo pikachu charmander squirtle caterpie raichu butterfree abra kadabra alakazam slowpoke"
   *
   * has 12 words.  This will allocate exactly enough space
   * for the words, then the array will be initialized to (dynamically allocated copies of) those
   * words. A zero size array is okay. Passing in a null pointer creates a zero size array.
   */
  explicit WordArray(const char *words);

  /* Deallocates any words and the array itself.
   */
  ~WordArray();

  /* Prints the words in the array to os, on a single line
   * with a single space between words. There is no 
   * space after the last word, but there is a newline
   * (even if there are no words).
   */
  std::ostream & print(std::ostream & os) const;

  /* Finds the first occurrence of the word in the array and if found,
   * returns a pointer to that word in the array.  Otherwise returns
   * nullptr.
   */
  const char * findFirst(const char * word) const;

  /* Searches for every occurrence of word in the array, and removes
   * that word from the array (deallocating the memory for that word).
   * The relative order of remaining words is not changed.
   * Words are shifted towards the beginning if needed so there are no
   * gaps between words.
   * The max size of the array is not changed. Returns the number of
   * words removed.
   */
  size_t removeAll(const char * word);

  /* Appends copies of the words from src onto this array.  If this
   * array does not have enough space to hold all the words, exactly
   * enough space should be dynamically allocated to hold all the
   * words before appending. Appending the same list onto itself is okay.
   */
  void append(const WordArray & src);
};



#endif
