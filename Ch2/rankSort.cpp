/*
 * filename: rankSort.cpp
 * description: 名次排序相关算法
 * author: QRQ
 */
#include "../common/common.h"
#include <algorithm>
#include <iostream>

template <class T>
void rank(T arrayToRank[], const int& arrayLength, int rankToSave[]) {
  // 计算数组的名次, 名次=更小的数字个数+左侧相同的数字个数
  for (int i = 0; i < arrayLength; ++i) {
    rankToSave[i] = 0;
  }

  for (int i = 1; i < arrayLength; ++i) {
    for (int j = 0; j < i; ++j) {
      if (arrayToRank[j] <= arrayToRank[i]) {
        rankToSave[i]++;
      }
      else {
        rankToSave[j]++;
      }
    }
  }
}


void testForRank(void) {
  int length = 5;
  int a[] = {3, 1, 5, 7, 4};
  int r[length];

  rank(a, length, r);

  printArray(a, length);
  std::cout << std::endl;
}


template <class T>
void countSort(T arrayToSort[], const int& length, int rankRecord[]) {
  // 计数排序, 需要生成一个临时数组作为中转
  T *tmpArray = new T [length];

  for (int i = 0; i < length ; ++i) {
    tmpArray[rankRecord[i]] = arrayToSort[i];
  }

  for (int i = 0; i < length ; ++i) {
    arrayToSort[i] = tmpArray[i];
  }

  delete [] tmpArray;
}


void testForCountSort(void) {
  int length = 5;
  int a[] = {3, 5, 1, 4, 2};
  int b[length];

  rank(a, length, b);
  countSort(a, length, b);

  printArray(a, length);
  std::cout << std::endl;

}


template <class T>
void inPalceSort(T arrayToSort[], const int& length, T rankRecord[]) {
  // 计数排序的改进版, 原地排序, 无需额外空间
  for (int i = 0; i < length; ++i) {
    while (rankRecord[i] != i) {
      int tmpRank = rankRecord[i];
      std::swap(arrayToSort[i], arrayToSort[tmpRank]);
      std::swap(rankRecord[i], rankRecord[tmpRank]);
    }
  }
}


void testForInPlaceSort(void) {
  int length = 10;
  int a[] = {3, 5, 4, 7, 1, 2, 9, 6, 8, 0};
  int r[length];

  rank(a, length, r);
  inPalceSort(a, length, r);

  printArray(a, length);
  std::cout << std::endl;
}

int main(void)
{
  //testForRank();
  // testForCountSort();
  testForInPlaceSort();
  return 0;
}
