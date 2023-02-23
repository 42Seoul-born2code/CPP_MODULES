#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include<iostream>
#include"ICharacter.hpp"
#include"AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string	name;
	AMateria	*inven[4];

public:
	Character();
	Character(std::string name);
	~Character();
	Character(const Character& character);
	Character& operator=(const Character& character);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif