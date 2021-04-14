#include <iostream>

template<class Tarr, class Tval>
void fillArrayWithValue(Tarr& arrayToFilled, const int& start, const int& end,
                        const Tval& valueToFill) {
  for (int i = start; i < end; ++i)
    arrayToFilled[i] = valueToFill;
}

int main(void)
{
  int nums[10];
  fillArrayWithValue(nums, 3, 6, 10);

  for (int i = 0; i < 10; ++i) {
    std::cout << nums[i] << std::endl;
        }

  return 0;
}
