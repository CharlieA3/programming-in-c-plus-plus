#ifndef CSTRINGLIB_HPP
#define CSTRINGLIB_HPP

namespace cstring {

  typedef unsigned long size_t;

  size_t strlen(const char *str);
  char *strncpy(char *destination, const char *source, size_t num);
  char *strncat(char *destination, const char *source, size_t num);
  int strcmp(const char *str1, const char *str2);
  const char *strchr(const char *str, int character);
  const char *strrchr(const char *str, int character);
  const char *strstr(const char *str1, const char *str2);
  char *strtok(char *str, const char *delimiters);

}

#endif
