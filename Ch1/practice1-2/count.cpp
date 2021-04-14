#include <iostream>

template<class Tarr, class Tval>
const int countVlaueInArray(const Tarr& arr, const int& arrayLength, const Tval value){
  int count = 0;
  for (int i = 0; i < arrayLength; ++i) {
    if (value == arr[i])
      count++;
  }
  return count;
}

int main(void)
{
  int nums[] = { 1, 2, 2, 3, 3, 2, 1, 2 };
  const int valNum = countVlaueInArray(nums, 8, 2);

  std::cout << valNum << std::endl;
  return 0;
}
