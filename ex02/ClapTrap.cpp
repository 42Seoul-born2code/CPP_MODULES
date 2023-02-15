#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap is created" << std::endl;
	this->hp_ = 10;
	this->ep_ = 10;
	this->damage_ = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap " << name << " is created" << std::endl;
	this->name_ = name;
	this->hp_ = 10;
	this->ep_ = 10;
	this->damage_ = 0;
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
	this->name_ = src.getName();
	this->hp_ = src.getHp();
	this->ep_ = src.getEp();
	this->damage_ = src.getDamage();
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
	return hp_;
}

void ClapTrap::setHp(unsigned int hp)
{
	hp_ = hp;
}

unsigned int ClapTrap::getEp() const 
{
	return ep_;
}

void ClapTrap::setEp(unsigned int ep)
{
	ep_ = ep;
}

unsigned int ClapTrap::getDamage() const
{
	return damage_;
}

void ClapTrap::setDamage(unsigned int damage)
{
	damage_ = damage;
}

CT_STATUS ClapTrap::checkStatus()
{
	if (hp_ == 0)
		return DEAD;
	else if (ep_ == 0)
		return NO_ENERGY_POINT;
	else
		return (ALIVE);
}

void ClapTrap::printStatus()
{
	std::cout 	<< name_ + " ( "
				<< "HP : " << hp_ << " / "
				<< "EP : " << ep_  << " ) "
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

	this->ep_ -= 1;
	std::cout 	<< "ClapTrap " + name_
				<< " attacks " + target << ", causing "
				<< damage_ << " points of damage!"
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

	if (this->hp_ < amount)
		this->hp_ = 0;
	else
		this->hp_ -= amount;
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

	this->ep_ -= 1;
	this->hp_ += amount;
	std::cout	<< "ClapTrap " + name_
				<< " is repaired " << amount << " points of hits!"
				<< std::endl;
}
