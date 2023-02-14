#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
	무기가 없는 것을 용인하면 예외처리를 해주어야 하는 단점이 존재한다.
*/

int main (void)
{
	{	
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
