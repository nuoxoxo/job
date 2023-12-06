/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nxu              ...   ::::::::.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : name("") {} // new

void	Zombie::set_name(std::string name)
{
	if (name == "")
		this->name = "T-1000";
	else
		this->name = name;
}

std::string	Zombie::get_name(void) const
{
	return (this->name);
}

void	Zombie::label(void) const
{
	std::cout << _green "﹤" << this->name << "﹥" _reset;
	//std::cout << '<' << this->name << '>' << ' ';
}

void	Zombie::announce(void) const
{
	Zombie::label();
	std::cout << "BraiiiiiiinnnzzzZ... \n";
}

Zombie::~Zombie(void)
{
	Zombie::label();
	std::cout << _cyan "is destroyed. \n" _reset;
}
