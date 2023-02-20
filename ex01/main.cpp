#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define L_GREEN "\033[1;32m"
#define L_BLUE "\033[1;94m"
#define RESET "\033[0m"

int main(void) {
  {
    Animal *animals[100];

    std::cout << L_GREEN << "===========Create 100 Animals===========" << RESET << std::endl;
    for (int i = 0; i < 50; i++) animals[i] = new Dog();
    for (int i = 50; i < 100; i++) animals[i] = new Cat();

    std::cout << L_GREEN << "===========makeSound()===========" << RESET << std::endl;
    for (int i = 0; i < 50; i++) animals[i]->makeSound();
    for (int i = 50; i < 100; i++) animals[i]->makeSound();

    std::cout << L_GREEN << "===========Delete 100 Animals===========" << RESET << std::endl;
    for (int i = 0; i < 50; i++) delete animals[i];
    for (int i = 50; i < 100; i++) delete animals[i];

    std::cout << L_GREEN << "===========Check DeepCopy : Copy Constructor===========" << RESET << std::endl;
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

    std::cout << L_GREEN << "===========Check DeepCopy : Assignment Operator===========" << RESET << std::endl;
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

    std::cout << L_GREEN << "===========Destructor called===========" << RESET << std::endl;
  }

  std::cout << L_GREEN << "===========Leaks check===========" << RESET << std::endl;
  system("leaks outfile");

  return 0;
}