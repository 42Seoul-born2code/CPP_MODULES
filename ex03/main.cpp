#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"


/*
	인터페이스
	- 모든 기능을 추상화로 정의만 하고 구현은 하지 않은것을 의미한다.

	다형성 구현
	- 상속과 인터페이스로 구현하는 다형성
	- 인터페이스는 구현체클래스에서 인터페이스의 메서드들을 재정의하면서 다형성을 가능하게 한다.

	상속 vs 인터페이스
	- 다형성을 위해서 2개의 선택권이 있는것이다.
	
	상속
	- 상속을 통해 다형성을 제공하면 자식클래스와 부모클래스는 강하게 결합되게 된다. 
	결합도는 변경에 유연하지 않게 하는 큰 장애물 이다.
	부모클래스를 상속받은 자식클래스에서는 부모클래스의 모든 메서드를 그대로 사용할 수 있다. 
	원치않은 메서드들도 상속되기 때문에 의도치 않은 버그도 발생시킬 수 있다.

	인터페이스
	- 인터페이스를 사용해서 프로그래밍을 하면 구체 클래스를 사용하지 않기 때문에 유연성이 올라간다.
	- 객체지향 개념에 맞게 잘 정돈된 설계를 위해 사용한다.
	- 재사용의 문제나 관리적 측면에서 편리하다.

	순수가상함수와 추상 클래스
	- 순수 가상함수를 선언한 클래스는 인스턴스 생성을 할 수 없다.
	- 추상 클래스를 상속한 자식 클래스는 순수 가상함수를 구현해야 인스턴스를 생성할 수 있다.


*/


/*

구현해야 할 클래스는 다음과 같이 7개
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
	tmp = src->createMateria("invalid");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	delete bob;
	delete me;
	delete src;
	system("leaks outfile");	
	return 0;
}