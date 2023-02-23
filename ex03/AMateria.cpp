#include"AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria &aMateria)
{
	this->type = aMateria.type;
}

AMateria& AMateria::operator=(const AMateria &aMateria)
{
	this->type = aMateria.type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}