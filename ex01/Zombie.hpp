#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie(void);
		Zombie(const std::string &name);
		~Zombie(void);
		void	SetName(std::string name);
		void	Announce(void);
};

Zombie* ZombieHorde(int N, std::string name);


#endif