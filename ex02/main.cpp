#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
  {
    Animal *animals[10];

    std::cout << "===========Create 10 Animals===========" << std::endl;
    for (int i = 0; i < 5; i++) animals[i] = new Dog();
    for (int i = 5; i < 10; i++) animals[i] = new Cat();

    std::cout << "===========makeSound()===========" << std::endl;
    for (int i = 0; i < 5; i++) animals[i]->makeSound();
    for (int i = 5; i < 10; i++) animals[i]->makeSound();

    std::cout << "===========Delete 10 Animals===========" << std::endl;
    for (int i = 0; i < 5; i++) delete animals[i];
    for (int i = 5; i < 10; i++) delete animals[i];

    std::cout << "===========Check DeepCopy : Copy Constructor===========" << std::endl;
    Dog src;
    Dog dst(src);

    Dog tmp;
    dst = tmp;

    std::cout << "Address of src brain: " << src.getBrain() << std::endl;
    std::cout << "Address of dst brain: " << dst.getBrain() << std::endl;

    std::cout << "Address of src brain->ideas: " << src.getBrain()->getIdeas() << std::endl;
    std::cout << "Address of dst brain->ideas: " << dst.getBrain()->getIdeas() << std::endl;

	// std::cout << "===========Animal Abstract class check===========" << std::endl;
	// // 컴파일 에러
	// Animal animal; 
	// animal.makeSound();

    std::cout << "===========Destructor called===========" << std::endl;
  }

  std::cout << "===========Leaks check===========" << std::endl;
  system("leaks outfile");

  return 0;
}