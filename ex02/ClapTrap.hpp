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

/*
	상속을 위해 private에서 protected로 변경
	private는 상속 받았을 때 접근이 불가능함 
*/
class ClapTrap
{
	protected:
		std::string		name_;
		unsigned int	hp_;
		unsigned int	ep_;
		unsigned int 	damage_;

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