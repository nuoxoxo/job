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
#include "Weapon.hpp"


/*	setting		*/


Weapon::Weapon(std::string type): type(type)
{
	if (type != "")
	{
		this->type = type;
		return ;
	}
	this->type = love;
}

Weapon::~Weapon(void) {}

const std::string & Weapon::getType(void) const { return (this->type); }


/*	weapon action		*/


void	Weapon::setType(const std::string & type)
{
	//std::cout << "type : " << type <<  std::endl;
	if (type != "")
	{
		this->type = type;
		return ;
	}
	this->type = love;
}
