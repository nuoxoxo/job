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

void	randomChump(std::string name)
{

	Zombie	random_zombie(name);
	
	// deprecated
	
	/*
	Zombie	*random_zombie = newZombie(name);
	random_zombie->announce();
	delete	random_zombie; // the 3rd way to kill a zombie (embedded here)
	
	// It cannot go anyway outside this scope anyway so we kill it here
	*/
}
