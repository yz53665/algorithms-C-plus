#ifndef CURRENCY_H
#define CURRENCY_H

#include <ostream>
enum signType{plus, minus};

class currency {
public:
  currency(signType theSign = plus,
           unsigned long theDollars = 0,
           unsigned int theCents = 0);
  ~currency(){}

  void setValue(signType, unsigned long, unsigned int);
  void setValue(double);

  signType getSign() const {
    if (amount < 0)
      return minus;
    else
      return plus;
  }
  unsigned long getDollars() const {
    if (amount < 0)
      return (-amount) / 100;
    else
      return amount / 100;
  }
  unsigned int getCents() const {
    if (amount < 0)
      return -amount - getDollars() * 100;
    else
      return amount - getDollars() * 100;
  }

  currency operator+(const currency&) const;  // 不改变调用对象本身的值
  currency& operator+=(const currency&);    // 改变调用对象本身的值
  void output(std::ostream&) const;

private:
  long amount;
};

std::ostream &operator<<(std::ostream&, const currency&);

#endif /* CURRENCY_H */
