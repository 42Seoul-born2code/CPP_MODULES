#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

/*
AMateria → Interface of Cure & Ice
Cure
Ice
ICharacter → Interface of Character
Character
IMateriaSource → Interface of MateriaSource
MateriaSource

사용자 : Character
Cure와 Ice같은 Amateria를 Interface로 하는 물질을 소지할 수 있다.
Character는 AMateria에 대해 equip, unequip, use 라는 상호작용 가능

IMateriaSource를 interface로 하는 MateriaSource를 이용해야 한다.
MateriaSource를 이용하여 물질을 생성하기 전에는 선행적으로 물질에 대한 학습이 필요하다.
이를 위해 learnMateria와 createMateria가 있다.

Character는 AMateria*를 4개까지 이용할 수 있다.


*/

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}