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


HumanB::HumanB(std::string _) : name(_), weapon(nullptr) {}

HumanB::~HumanB(void) {}

Weapon	& HumanB::getWeapon(void) const { return (*(this->weapon)); }


/*	actions		*/


void	HumanB::setWeapon(Weapon & weapon)
{
	this->weapon = & weapon;
}

void	HumanB::attack(void) const
{
	std::cout << _gn << this->name << _rs;
	if (this->weapon->getType() != love)
	{
		std::cout << " picks up a large ";
		std::cout << _cn << this->weapon->getType() << _rs;
		std::cout << " and retreats westward. \n";
	}
	else
	{
		std::cout << " gets ";
		std::cout << _cn << this->weapon->getType() << _rs;
		std::cout << ", smiles and says, ";
		std::cout << "\"i cannot fight with nothing.\" \n";
	}
}
