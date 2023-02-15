#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/*
  virtual를 통해서 가상 함수, 가상 소멸자가 되는데
  해당 키워드는 부모 클래스에 대한 포인터나 참조에서 자식 클래스를 가리킬 수 있는데,
  이때 당연히 자식 클래스의 함수가 실행돼야하지만, 의도와는 다르게 부모 클래스 함수가 실행된다.
  따라서 해당 함수를 자식 클래스에서 변환했을 수 있다는 걸 알려주는 키워드

  소멸자 앞에 붙은 키워드는 더 중요하게 부모 클래스에 대한 포인터나 참조가 자식 클래스를 가리키고 있을 때 
  delete를 선언하면 부모 클래스만 소멸되고 자식 클래스가 메모리 누수가 되는 것을 방지 하기 위해 가상 소멸자 사용

*/

class ScavTrap : public ClapTrap {
 public:
  ScavTrap(void);
  ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &copy);

  ScavTrap &operator=(const ScavTrap &src);

  virtual void attack(const std::string &target);
  void guardGate();

  virtual ~ScavTrap();
};

#endif