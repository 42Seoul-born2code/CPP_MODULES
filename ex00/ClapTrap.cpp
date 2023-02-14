#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap is created" << std::endl;
	this->hitPoints_ = 10;
	this->energyPoints_ = 10;
	this->attackDamage_ = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap" << name << " is created" << std::endl;
	this->name_ = name;
	this->hitPoints_ = 10;
	this->energyPoints_ = 10;
	this->attackDamage_ = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name_ << " is destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	this->name_ = src.name_;
	this->hitPoints_ = src.hitPoints_;
	this->energyPoints_ = src.energyPoints_;
	this->attackDamage_ = src.attackDamage_;
	return (*this);
}

const std::string &ClapTrap::getName() const
{
	return name_;
}

void ClapTrap::setName(const std::string &name)
{
	name_ = name;
}

unsigned int ClapTrap::getHp() const
{
	return hitPoints_;
}

void ClapTrap::setHp(unsigned int hp)
{
	hitPoints_ = hp;
}

unsigned int ClapTrap::getEp() const 
{
	return energyPoints_;
}

void ClapTrap::setEp(unsigned int ep)
{
	energyPoints_ = ep;
}

unsigned int ClapTrap::getDamage() const
{
	return attackDamage_;
}

void ClapTrap::setDamage(unsigned int damage)
{
	attackDamage_ = damage;
}

CT_STATUS ClapTrap::checkStatus()
{
	if (hitPoints_ == 0)
		return DEAD;
	else if (energyPoints_ == 0)
		return NO_ENERGY_POINT;
	else
		return (ALIVE);
}

void ClapTrap::printStatus()
{
	std::cout 	<< "ClapTrap " + name_ + " ( "
				<< "HP : " << hitPoints_ << " / "
				<< "EP : " << energyPoints_  << " ) "
				<< std::endl;
}

void ClapTrap::attack (const std::string &target)
{
	if (checkStatus() != ALIVE)
	{
		std::cout << "Attack Fail : ";
		printStatus();
		return ;
	}

	this->energyPoints_ -= 1;
	std::cout 	<< "ClapTrap " + name_
				<< " attacks " + target << ", causing "
				<< attackDamage_ << " points of damage!"
				<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (checkStatus() == DEAD)
	{
		std::cout << "Damaged Fail : ";
		printStatus();
		return ;
	}

	if (this->hitPoints_ < amount)
		this->hitPoints_ = 0;
	else
		this->hitPoints_ -= amount;
	std::cout	<< "ClapTrap " + name_
				<< " take " << amount << " points of damage!"
				<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (checkStatus() != ALIVE)
	{
		std::cout << "Repaired Fail : ";
		printStatus();
		return;
	}

	this->energyPoints_ -= 1;
	this->hitPoints_ += amount;
	std::cout	<< "ClapTrap " + name_
				<< " is repaired " << amount << " points of hits!"
				<< std::endl;
}
