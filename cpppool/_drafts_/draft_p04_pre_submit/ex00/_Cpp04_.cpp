/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _Cpp04_.cpp                                          :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/16 14:31:23 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_Cpp04_.hpp"

void	print_canon(std::string funcName, std::string canonName)
{
	std::cout << LOWKEY << funcName << ' ' << canonName << called REST;
}

void	print_ending(int i)
{
	std::cout
	<< LOWKEY nl 
	<< ":::::::::::: end test " << i << " ::::::::::::" nl2 REST;
}

void	print_ending(void)
{
	std::cout
	<< LOWKEY nl 
	<< ":::::::::::: end test ::::::::::::" nl2 REST;
}