#ifndef COMMON_H
#define COMMON_H

#include <iostream>

template <class T> void printArray(T array[], const int &length) {
  for (int i = 0; i < length; ++i) {
    std::cout << array[i] << " ";
  }
}

#endif /* COMMON_H */
