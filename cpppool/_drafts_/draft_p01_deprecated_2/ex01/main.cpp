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

int	main(const int c, const char **v)
{
	std::string		arg1;
	std::string		name;
	int			numb;

	if (c > 1)
		arg1 = std::string(v[1]);
	numb = 42;
	name = "";
	if (c == 2)
	{
		if (isdigit(v[1][0]))
			numb = stoi(arg1);
		else
			name = arg1;

	}
	else if (c > 2)
	{
		if (isdigit(v[1][0]))
			numb = std::stoi(arg1);
		name = std::string(v[2]);
	}
	//std::cout << numb << '\n' << name << std::endl; // debugger

	Zombie		*flock = zombieHorde(numb, name);

	announce_foreach(numb, flock);

	delete [] flock;
}
