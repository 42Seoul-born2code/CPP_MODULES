#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main(void) {
  std::cout << "===========Correct Way===========" << std::endl;
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;

  i->makeSound();//will output the cat sound!
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

  iw->makeSound();//will output the cat sound!
  jw->makeSound();
  metaw->makeSound();

  delete metaw;
  delete jw;
  delete iw;

  return 0;
}