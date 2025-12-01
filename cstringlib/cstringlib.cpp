#include "cstringlib.hpp"

namespace cstring
{

  size_t strlen(const char *str)
  {
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
      length++;
    }
    return length;
  }

  char *strncpy(char *destination, const char *source, size_t num)
  {
    // this allows me to loop until a certain character, but keeps the index "global" so I can use it in another for loop
    size_t i = 0;
    for (; i < num && source[i] != '\0'; i++)
    {
      destination[i] = source[i];
    }
    for (; i < num; i++)
    {
      destination[i] = '\0';
    }

    return destination;
  }

  // at this point I realized I could usewhile loops
  char *strncat(char *destination, const char *source, size_t num)
  {
    size_t i = 0;
    // loop until I find the end of the destination string, not restricted by num
    while (destination[i] != '\0')
    {
      i++;
    }

    size_t j = 0;
    while (j < num && source[j] != '\0')
    {
      destination[i + j] = source[j];
      j++;
    }

    // add null termination
    *(destination + i + j) = '\0';

    return destination;
  }

  int strcmp(const char *str1, const char *str2)
  {
    size_t i = 0;
    while (str1[i] == str2[i] && str1[i] != '\0')
    {
      i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
    {
      return 0;
    }
    else if (str1[i] < str2[i])
    {
      return -1;
    }
    else
      return 1;
  }

  const char *strchr(const char *str, int character)
  {
    size_t i = 0;
    while (str[i] != (char)character && str[i] != '\0')
    {
      i++;
    }
    if (str[i] == (char)character)
    {
      return &str[i];
    }
    return nullptr;
  }

  const char *strrchr(const char *str, int character)
  {
    size_t i = 0;
    while (str[i] != '\0')
    {
      i++;
    }
    for (size_t j = i; j > 0; j--)
    {
      if (str[j - 1] == (char)character)
      {
        return &str[j - 1];
      }
    }
    return nullptr;
    // size_t index_last_char = -1;
    // // inside this while loop the scope does not change so I can modify the index for the last character and return if it is greater than -1
    // while (str[i] != '\0')
    // {
    //   if (str[i] == (char)character)
    //     index_last_char = i;
    //   i++;
    // }
    // if ((int)index_last_char >= 0)
    //   return &str[index_last_char];
    // return nullptr;
  }

  const char *strstr(const char *str1, const char *str2)
  {
    size_t i = 0;
    const char *found_something = nullptr;
    while (str1[i] != '\0')
    {
      // if we find a matching character, then we want to loop through the rest of str2 so we can find if the whole thing matches
      if (str1[i] == str2[0])
      {
        found_something = &str1[i];
        size_t j = 0;
        while (str2[j] != '\0' && str1[i + j] != '\0')
        {
          if (str1[i + j] != str2[j])
            found_something = nullptr;
          j++;
        }
      }
      i++;
    }
    return found_something;
  }

  char *strtok(char *str, const char *delimiters)
  {
    (void)str;
    (void)delimiters;
    return nullptr; // OPTIONAL (remove this line after implementing)
  }

}
