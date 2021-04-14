#include <exception>
#include <iostream>
#include <stdexcept>

template <class Ta, class Tb, class Tc>
Ta add3num(const Ta& a, const Tb& b, const Tc& c)
{
  if (a <= 0 || b <= 0 || c <= 0) {
    throw "All parameter should be > 0";
  }
  return a + b * c;
}

int main(void)
{
  int result = 0;
  int a = 3, b = 2, c = 0;
  try {
    result = add3num(a, b, c);
  } catch (char const* e) {
    std::cout << "the parameter to add3num is " << std::endl;
    std::cout << a << ", " << b << " and " << c << std::endl;
    std::cout << e << std::endl;
    return 0;
  }

  std::cout << result << std::endl;

  return 0;
}
