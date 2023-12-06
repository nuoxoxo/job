/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nxu              ...   ::::::::.fi       */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* *********************  ʕ • ᴥ•ʔ  mode: todo  (⊙. ⊙ )  ********************* */

#include "Zombie.hpp"

int	main()
{
	Zombie	matt("Matthew");
	Zombie	*luke = newZombie("Luke");

	storyline_1();
	matt.announce();

	storyline_2();
	luke->announce();

	// ------8<------

	storyline_3();
	randomChump("Paul");

	storyline_4();
	delete	luke;
}
