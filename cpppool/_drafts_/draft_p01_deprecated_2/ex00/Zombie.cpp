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

Zombie::Zombie(std::string name) : name(name) {}

//

std::string	Zombie::get_name(void) const
{
	return (this->name);
}

void	Zombie::label(void) const
{
	std::cout << _GREEN_ "﹤" << this->name << "﹥" _REST_; // diff signs

	/* to cleanup on submit */
	// std::cout << '<' << this->name << '>' << ' '; // norm -gt -lt
}

void	Zombie::announce(void) const
{
	Zombie::label();
	std::cout << "BraiiiiiiinnnzzzZ... \n";
}

Zombie::~Zombie(void)
{
	Zombie::label();
	std::cout << "is dead. \n";
}


