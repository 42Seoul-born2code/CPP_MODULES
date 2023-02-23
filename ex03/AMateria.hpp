#ifndef AMATERIA_HPP_
#define AMATERIA_HPP_

#include <string>
#include <iomanip>
#include <iostream>

#define W_SIZE              45
#define AM_SIZE             4

/*

헤더의 상호 참조 문제. 
AMateria에서 use의 인자 target의 자료형으로 ICharacter를 사용하기 위해 해당 헤더를 넣어뒀는데, 
ICharacter에서도 equip의 인자 자료형이 AMateria이기 때문에 서로를 참조하게 되어 컴파일이 되지 않는다.

이를 해결하기 위해 클래스를 "전방 선언"

전방 선언이란 이러한 클래스가 있다고 미리 선언하되, 해당 내용에 대해서는 필요한 경우에만 소스 파일(.cpp 파일)에 따로 헤더를 선언해주는 것을 말한다.
*/

class ICharacter;

class AMateria {
 protected:
  std::string _type;

 public:
  const std::string& getType(void) const;

  virtual AMateria* clone(void) const = 0;
  virtual void use(const ICharacter& ic);

  AMateria& operator=(const AMateria& am);

  AMateria(void);
  AMateria(const std::string& type);
  AMateria(const AMateria& am);
  virtual ~AMateria(void);
};

#endif