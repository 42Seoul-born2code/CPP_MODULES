#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
  private:
    Brain *brain_;
  public:
    Cat(void);
    Cat(const Cat &copy);
    virtual ~Cat();

    Cat &operator=(const Cat &src);
    Brain *getBrain() const;
    virtual void makeSound(void) const;
};

#endif