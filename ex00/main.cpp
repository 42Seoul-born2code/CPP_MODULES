#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

/*
  c++ 에서는 부모 클래스의 포인터여도 자식 클래스의 객체 주소를 담을 수 있다. 이를 "업캐스팅" 이라고 한다.

  이때 , 부모 클래스다 보니 자식 클래스에서 오버라이딩한 함수를 실행시키려는 상황에 부모 클래스 원래 함수 실행이 되는 문제 발생 -> virtual 키워드를 붙인다. (부모 클래스 함수에)

	Overriding 부분을 짚자면, 기반 클래스에서 재정의 하려는 함수는 virtual로 명시해야 하고, 파생 클래스의 소멸자는 virtual로 명시해야 한다.

  클래스를 const로 선언했다면 멤버 함수 끝에 const를 붙이지 않은 함수의 사용은 금지된다. 따라서 makesound에도 const 를 붙여야한다.

  wrong aniaml은 virtual이 없다.
*/

int main(void) {
  std::cout << "===========Correct Way===========" << std::endl;
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;

  // 오버라이딩 된 냥이, 멍이 소리가 나올 것.
  i->makeSound();
  j->makeSound();
  meta->makeSound();

  delete meta;
  delete j;
  delete i;

  std::cout << "===========Wrong Way===========" << std::endl;

  const WrongAnimal *metaw = new WrongAnimal();
  const WrongAnimal *jw = new WrongDog();
  const WrongAnimal *iw = new WrongCat();

  std::cout << jw->getType() << " " << std::endl;
  std::cout << iw->getType() << " " << std::endl;

  // 오버라이딩 되지 않은 냥이, 멍이 소리가 나온다. 즉 부모 소리
  iw->makeSound();
  jw->makeSound();
  metaw->makeSound();

  delete metaw;
  delete jw;
  delete iw;

  return 0;
}