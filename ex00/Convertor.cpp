#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Convertor.hpp"

// Constructor & Destructor
Convertor::Convertor() : value_(0) {}
Convertor::Convertor(const std::string &value) : value_(value) {}
Convertor::Convertor(const Convertor &copy) : value_(copy.value_) {}
Convertor::~Convertor() {}

// Operator Overload
Convertor &Convertor::operator=(const Convertor &src) {
  this->value_ = src.value_;
  return (*this);
}

/*
매개변수로 받은 값 num이 자기 자신과 같지 않은 경우는, C++에서 NaN (Not-a-Number) 값일 때 발생합니다. 
NaN은 계산 중에 정의되지 않거나 무한대 값을 계산할 수 없는 경우 등에 사용되며, 이러한 경우에 해당하는 값으로 NaN을 반환합니다.

실제로 NaN은 "not equal to anything, including itself" (자기 자신을 포함하여 아무 값과도 같지 않다)는 특징을 갖고 있어서, 이러한 특성을 활용해 isNan 함수는 num 값이 NaN인지 판별합니다.

*/

// Method
bool Convertor::isNan(double num) const {
  if (num != num)
    return true;
  return false;
}

/*
C++에서, 양의 무한대는 1.0 / 0.0 으로 표현하고, 음의 무한대는 -1.0 / 0.0으로 표현합니다. 이것은 부동소수점 연산에서 특수한 값으로, 특별한 의미를 가지며 무한대로 표현됩니다.
*/

bool Convertor::isInf(double num) const {
  if (num == (1.0 / 0.0) || num == (-1.0 / 0.0))
    return true;
  return false;
}

/*
strtod() 함수가 이 문자열을 double형으로 변환하고, 그 결과를 반환합니다. 
반환된 값을 int형으로 변환하여 num에 저장하기 위해 static_cast<int>를 사용하였습니다. 
이렇게 함으로써 double형에서 int형으로의 형변환을 수행하면서, 소수점 이하의 값은 버리고, 정수 부분만을 유지하게 됩니다.

static_cast를 사용하는 이유는, C++에서는 데이터 타입 간의 명시적인 형변환을 할 때, static_cast를 이용하여 명시적으로 형변환을 하도록 권장하고 있기 때문입니다.

데이터 타입 간의 명시적인 형변환을 하는 이유는, 다른 데이터 타입으로 변환하여 저장하거나 계산할 때, 데이터 손실을 최소화하기 위해서입니다. 
예를 들어 double형 데이터를 int형으로 변환할 때, 소수점 이하 값은 버려지므로 데이터 손실이 발생합니다. 
이때 static_cast를 사용하여 명시적으로 형변환을 하면, 컴파일러가 형변환을 할 때 발생할 수 있는 오류를 검출해 줍니다. 
따라서 static_cast를 사용하여 명시적으로 형변환을 하는 것이 안전하고 권장되는 방법
*/


// 포인터가 들어가야 해서 value.c_str()
void Convertor::convertChar() const {
  int num;

  std::cout << "char: ";

  if (value_.length() == 1) {
    num = static_cast<int>(value_[0]);
  } else {
    num = static_cast<int>(strtod(value_.c_str(), NULL));
  }

  if ((num > 32 && num < 48) || (num > 57 && num < 127)) {
    std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
  } else if ((num >= 0x00) && (num <= 0xff)) {
    std::cout << "Non displayable" << std::endl;
  } else {
    std::cout << "impossible" << std::endl;
  }
}

void Convertor::convertInt() const {
  int num = std::atoi(value_.c_str());
  std::cout << num << std::endl;

  std::cout << "int: ";
  if (num == 0 && value_[0] != '0') {
    std::cout << "impossible" << std::endl;
  } else {
    std::cout << num << std::endl;
  }
}
void Convertor::convertFloat() const {
  float num = static_cast<float>(std::atof(value_.c_str()));

  std::cout << "float: ";
  if (num == 0 && value_[0] != '0') {
    std::cout << "impossible" << std::endl;
  } else if (isNan(num) || isInf(num) || (std::round(num) != num)) {
    std::cout << num << "f" << std::endl;
  } else {
    std::cout << num << ".0f" << std::endl;
  }
}
void Convertor::convertDouble() const {
  double num = std::atof(value_.c_str());

  std::cout << "double: ";
  if (num == 0 && value_[0] != '0') {
    std::cout << "impossible" << std::endl;
  } else if (isNan(num) || isInf(num) || (std::round(num) != num)) {
    std::cout << num << std::endl;
  } else {
    std::cout << num << ".0" << std::endl;
  }
}
void Convertor::convert() const {
  convertChar();
  convertInt();
  convertFloat();
  convertDouble();
}

// Getter & Setter
const std::string &Convertor::GetValue() const {
  return value_;
}
void Convertor::SetValue(const std::string &value) {
  value_ = value;
}