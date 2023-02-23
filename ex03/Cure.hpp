#ifndef CURE_HPP
# define CURE_HPP

#include"AMateria.hpp"

class Cure : public AMateria
{
private:

public:
	Cure();
	Cure(std::string name);
	Cure(const Cure& cure);
	Cure &operator=(const Cure& cure);
	~Cure();
	AMateria* clone() const;
};

#endif