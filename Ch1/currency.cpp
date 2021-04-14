#include "currency.h"
#include "illegalParameterValue.h"

currency::currency(signType theSign, unsigned long theDollars,
                   unsigned int theCents) {
  setValue(theSign, theDollars, theCents);
}


void currency::setValue(signType theSign, unsigned long theDollars,
                   unsigned int theCents) {
  if (theCents > 99) {
    throw illegalParameterValue("cents should be < 100");
  }

  amount = theDollars * 100 + theCents;
  if (theSign == minus) amount = -amount;
}


void currency::setValue(double theAmount) {
  if (theAmount < 0)
    amount = (long) (theAmount - 0.001) * 100;
  else
    amount = (long) (theAmount + 0.001) * 100;
}

currency currency::operator+(const currency &addend) const {
  currency newCurrency;
  newCurrency.amount = addend.amount + amount;
  return newCurrency;
}


currency& currency::operator+=(const currency &x) {
  amount += x.amount;
  return *this;
}


void currency::output(std::ostream& out) const {
  long theAmount = amount;
  if (theAmount < 0) {
    out << "-";
    theAmount = -theAmount;
  }

  long theDollars = theAmount / 100;
  out << '$' << theDollars << '.';

  long theCents = theAmount % 100;
  if (theCents < 10)
    out << 0;
  out << theCents;
}


std::ostream& operator<<(std::ostream& out, const currency& x) {
  x.output(out);
  return out;
}
