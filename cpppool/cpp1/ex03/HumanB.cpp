/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By: nuo <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuo               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nuo              ...   ::::::::.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "HumanB.hpp"


/*	setting		*/


HumanB::HumanB(std::string _) : name(_), weapon(NULL) {}

HumanB::~HumanB(void) {}

Weapon	& HumanB::getWeapon(void) const { return (*(this->weapon)); }


/*	actions		*/


void	HumanB::setWeapon(Weapon & weapon)
{
	this->weapon = & weapon;
}

void	HumanB::attack(void) const
{
	std::cout << _GREEN_ << this->name << _REST_;
	if (this->weapon->getType() != _LOVE_)
	{
		std::cout << " picks up a large ";
		std::cout << _CYAN_ << this->weapon->getType() << _REST_;
		std::cout << " and retreats westward. \n";
	}
	else
	{
		std::cout << " gets ";
		std::cout << _CYAN_ << this->weapon->getType() << _REST_;
		std::cout << ", smiles and says, ";
		std::cout << "\"i cannot fight with nothing.\" \n";
	}
}
