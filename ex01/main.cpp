#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/*
  Brain 클래스에서 복사대입연산자를 따로 추가해주지 않으면 깊은복사를 하지 못한다.

  
*/

int main(void) {
  {
    Animal *animals[10];

    std::cout  << "===========Create 10 Animals===========" << std::endl;
    for (int i = 0; i < 5; i++) animals[i] = new Dog();
    for (int i = 5; i < 10; i++) animals[i] = new Cat();

    std::cout  << "===========makeSound()===========" << std::endl;
    for (int i = 0; i < 5; i++) animals[i]->makeSound();
    for (int i = 5; i < 10; i++) animals[i]->makeSound();

    std::cout  << "===========Delete 10 Animals===========" << std::endl;
    for (int i = 0; i < 5; i++) delete animals[i];
    for (int i = 5; i < 10; i++) delete animals[i];

    std::cout  << "===========Check DeepCopy : Copy Constructor===========" << std::endl;
    Dog src;
    Dog dst(src);

    std::cout << "Address of src brain: " << src.getBrain() << std::endl;
    std::cout << "Address of dst brain: " << dst.getBrain() << std::endl;

    std::cout << "Address of src brain->ideas: " << src.getBrain()->getIdeas() << std::endl;
    std::cout << "Address of dst brain->ideas: " << dst.getBrain()->getIdeas() << std::endl;

    src.getBrain()->setIdea(0, "src");
    dst.getBrain()->setIdea(0, "dst");

    std::cout << "src ideas[0]: " << src.getBrain()->getIdeas()[0] << std::endl;
    std::cout << "dst ideas[0]: " << dst.getBrain()->getIdeas()[0] << std::endl;

    std::cout  << "===========Check DeepCopy : Assignment Operator===========" << std::endl;
    Cat cat;
    Cat copyCat = cat;

    std::cout << "Address of src brain: " << cat.getBrain() << std::endl;
    std::cout << "Address of dst brain: " << copyCat.getBrain() << std::endl;

    std::cout << "Address of src brain->ideas: " << cat.getBrain()->getIdeas() << std::endl;
    std::cout << "Address of dst brain->ideas: " << copyCat.getBrain()->getIdeas() << std::endl;

    cat.getBrain()->setIdea(0, "cat");
    copyCat.getBrain()->setIdea(0, "copyCat");

    std::cout << "cat ideas[0]: " << cat.getBrain()->getIdeas()[0] << std::endl;
    std::cout << "copyCat ideas[0]: " << copyCat.getBrain()->getIdeas()[0] << std::endl;

    std::cout  << "===========Destructor called===========" << std::endl;
  }

  std::cout  << "===========Leaks check===========" << std::endl;
  system("leaks outfile");

  return 0;
}