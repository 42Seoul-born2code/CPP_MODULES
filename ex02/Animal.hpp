#ifndef ANIMAL_HPP
#define ANIMAL_HPP

/*
  Animal을 객체로 만들어서 생기는 문제점을 피하기 위해 순수 가상 함수를 이용하여 추상 클래스로 만들자.

  순수 가상 함수는 반드시 재정의 해야만 하는 함수를 뜻한다. (virtual과 반대)
  또한 이러한 순수 가상 함수가 들어간 클래스를 추상 클래스라고 부른다.

  순수 가상 함수란 virtual 로 명시된 함수에 =0 을 붙임으로 해당 함수를 정의하지 않겠다는 의미.
  
  makeSound 메서드를 가지고 있는 클래스는 인터페이스가 된다.

*/

#include <string>

class Animal {
 protected:
  std::string type_;
 public:
  Animal(void);
  Animal(const Animal &copy);
  virtual ~Animal();

  Animal &operator=(const Animal &src);

  virtual void makeSound(void) const = 0;
  const std::string &getType() const;
};

#endif