#include "Weapon.hpp"

Weapon::Weapon( const std::string newType )
{
	type = newType;
};

Weapon::~Weapon() {};

const std::string&	Weapon::getType() const
{
	return type;
}

void	Weapon::setType( const std::string newType )
{
	type = newType;
}