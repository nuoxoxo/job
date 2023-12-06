/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/03 09:59:05 by nuxu             ###   ########.fr       */
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
		{
			std::stringstream ss(arg1);
			if (!ss.eof())
				ss >> numb;
			// no sscanf . no atoi
		}
		else
		{
			name = arg1;
		}

	}
	else if (c > 2)
	{
		if (isdigit(v[1][0]))
		{
			std::stringstream ss(arg1);
			if (!ss.eof())
				ss >> numb;	
			// no sscanf . no atoi
		}
		name = std::string(v[2]);
	}

	// don't hurt computer
	if (numb < 0 || numb > (int) 1e6)
	{
		return 1;
	}

	// the part that matters
	Zombie	*flock = zombieHorde(numb, name);
	announce_foreach(numb, flock);
	delete [] flock;
}
