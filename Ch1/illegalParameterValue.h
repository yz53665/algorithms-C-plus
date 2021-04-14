#ifndef ILLEGALPARAMETERVALUE_H
#define ILLEGALPARAMETERVALUE_H

#include <string>
#include <iostream>

class illegalParameterValue
{
public:
  illegalParameterValue(): message("Illegal parameter value") {}
  illegalParameterValue(const char* theMessage){
    message = theMessage;
  }
  void outputMessage() {std::cout << message << std::endl;}

private:
  std::string message;
};

#endif /* ILLEGALPARAMETERVALUE_H */
