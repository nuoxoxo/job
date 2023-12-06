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
#include "HumanA.hpp"


/*	setting		*/


HumanA::HumanA(std::string _, Weapon & __) : name(_), weapon(__) {}

HumanA::~HumanA(void) {}

Weapon	& HumanA::getWeapon(void) const { return (this->weapon); }


/*	actions		*/


void	HumanA::attack(void) const
{
	std::string		type;

	type = this->weapon.getType();
	std::cout << _GREEN_ << this->name << _REST_ ;
	if (type == _LOVE_)
	{
		std::cout << " gets ";
		std::cout << _CYAN_ << type << _REST_ ;
		std:: cout << " and shouts, \"look! i always got a weapon.\" \n";
	}
	else
	{
		std::cout << " picks up a huge ";
		std::cout << _CYAN_ << type << _REST_ ;
		std::cout << ", screams and ... runs away. \n";
	}
}
