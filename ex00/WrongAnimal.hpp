#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
 protected:
  std::string type_;
 public:
  WrongAnimal(void);
  WrongAnimal(const WrongAnimal &copy);
  ~WrongAnimal();

  WrongAnimal &operator=(const WrongAnimal &src);

  void makeSound(void) const;
  const std::string &getType() const;
};

#endif