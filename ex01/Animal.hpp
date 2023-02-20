#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
 protected:
  std::string type_;
 public:
  Animal(void);
  Animal(const Animal &copy);
  virtual ~Animal();

  Animal &operator=(const Animal &src);

  virtual void makeSound(void) const;
  const std::string &getType() const;
};

#endif