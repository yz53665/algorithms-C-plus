#include <iostream>

template<class Ta, class Tb>
int innerProduct(const Ta& arrayA, const Tb& arrayB, const int& arrayLenth){
  int result = 0;
  for(int i=0; i < arrayLenth; ++i){
    result += (arrayA[i] * arrayB[i]);
  }
  return result;
}

int main(void)
{
  int arrayLenth = 5;
  int arrayA[] = {1, 2, 3, 4, 5};
  int arrayB[] = {1, 2, 3, 4, 5};

  int result = innerProduct(arrayA, arrayB, arrayLenth);
  std::cout << "result:" << result << std::endl;
  return 0;
}
