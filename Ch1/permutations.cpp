/*
  使用函数递归实现排列
*/
#include <iostream>
#include <iterator>
#include <type_traits>
#include <algorithm>

template <class T>
void permutations(T list[], int k, int m){
  if (k == m){
    copy(list, list+m, std::ostream_iterator<T>(std::cout, " "));
    std::cout << std::endl;
  }
  else {
    for (int i = k; i < m; ++i) {
      std::swap(list[k], list[i]);
      permutations(list, k+1, m);
      std::swap(list[k], list[i]);
    }
  }
}

int main(void) {
  int array[] = {1, 2, 3, 4};
  permutations(array, 0, 4);
  return 0;
}
