#include"Character.hpp"
Character::Character()
{
	for (int i = 0 ; i < 4 ; i++)
		this->inven[i] = NULL;
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0 ; i < 4 ; i++)
		this->inven[i] = NULL;
}

Character::~Character()
{
	for (int i = 0 ; this->inven[i] != NULL && i < 4 ; i++)
		delete this->inven[i];
}

Character::Character(const Character& character)
{
	this->name = character.name;
}

Character& Character::operator=(const Character& character)
{
	this->name = character.name;
	return (*this);
}

std::string const & Character::getName() const
{

}

void Character::equip(AMateria* m)
{
}
void Character::unequip(int idx)
{
	
}

void Character::use(int idx, ICharacter& target)
{

}