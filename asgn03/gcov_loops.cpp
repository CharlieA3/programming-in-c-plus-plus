unsigned int loop1(unsigned int x) {
  unsigned int r = 0;
  for (unsigned int ii = 0; ii < x; ++ ii) {
    ++ r; // LINE 1
  }
  return r;
}

unsigned int loop2(unsigned int x) {
  unsigned int r = 0;
  for (unsigned int ii = 0; ii < x; ii += 2) {
    for (unsigned int jj = 0; jj < 100; ++ jj) {
      if ((ii * jj) % 23 < 4) {
	++ r; // LINE 2
      }
    }
  }
  return r;
}

unsigned int loop3(unsigned int x) {
  unsigned int r = 0;
  for (unsigned int ii = 0; ii < x; ++ ii) {
    if ((ii * ii * ii) % 3 == 0) {
      r = loop2(ii % 10); // LINE 3
    }
  }
  return r;
}



int main() {
  unsigned int x = 100;
  x = loop1(x);
  x = loop2(x);
  x = loop3(x);
}
