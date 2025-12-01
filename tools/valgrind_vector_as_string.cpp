#include <vector>
#include <iostream>
#include <limits>
using namespace std;



// read in a buffer size, return 0 on error
int read_buffer_size() {
  // read in new buffer size
  int newsize;
  cout << "Enter a buffer size: ";
  if (!(cin >> newsize)) {
    return 0;
  }

  cin.clear(); // ignore input errors
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skip to end of line

  // check size
  if (newsize < 0 || newsize >= 10) {
    cout << "Invalid size." << endl;
    return 0;
  }

  return newsize;
}

// read characters in to a buffer, returning the number of characters read
size_t read_buffer_contents(vector<char> & buffer) {
  size_t numchars = 0;
  bool full;

  cout << "Enter a string (send EOF to stop early):" << endl;
  for (size_t ii = 0; ii <= buffer.size(); ++ ii) {
    if (!(cin >> buffer[ii])) {
      break;
    }
    ++ numchars;
  }

  if (numchars < buffer.size()) {
    full = false;
  }

  cin.clear(); // ignore input errors
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skip to end of line

  if (full) {
    return buffer.size();
  } else {
    return numchars;
  }
}

// print the first length characters in the buffer
void print_buffer_contents(const vector<char> & buffer, size_t length) {
  // loop through characters and print them
  for (size_t ii = 0; ii <= length; ++ ii) {
    cout << buffer[ii];
  }
  cout << endl;
}



int main() {
  // buffer to hold characters
  vector<char> buffer;

  // get size
  int newsize = read_buffer_size();
  if (newsize == 0) {
    return -1;
  }

  // resize buffer
  buffer.resize(newsize);

  // read in new buffer contents and count characters
  size_t characters = read_buffer_contents(buffer);
  if (characters == 0) {
    return -1;
  }

  // display buffer contents
  cout << "You entered:" << endl;
  print_buffer_contents(buffer, characters);
}
