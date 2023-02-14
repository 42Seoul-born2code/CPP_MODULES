#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

enum CT_STATUS
{
	DEAD,
	NO_ENERGY_POINT,
	ALIVE
};

class ClapTrap
{
	private:
		std::string		name_;
		unsigned int	hitPoints_;
		unsigned int	energyPoints_;
		unsigned int 	attackDamage_;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &src);

		const std::string &getName() const;
		void setName(const std::string &name);
		unsigned int getHp() const;
		void setHp(unsigned int hp);
		unsigned int getEp() const;
		void setEp(unsigned int ep);
		unsigned int getDamage() const;
		void setDamage(unsigned int damage);
		
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	printStatus();
		CT_STATUS checkStatus();
};

#endif