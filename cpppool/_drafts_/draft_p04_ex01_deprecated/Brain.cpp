/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   {}.cpp                                             :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/09 14:55:26 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


// canon

Brain::Brain()
{
	std::cout << LOWKEY << __FUNCTION__
	<< " Constructor" << called REST;
}

Brain::Brain(const Brain & dummy)
{
	*this = dummy;

	std::cout << LOWKEY << __FUNCTION__
	<< " Copy constructor" << called REST;
}

Brain & Brain::operator = (const Brain & dummy)
{
	int i = -1;
	while (++i < N)
		m_idea[i] = dummy.m_idea[i];
	
	std::cout << LOWKEY << __FUNCTION__
	<< " Copy assignment constructor" << called REST;

	return (*this);
}

Brain::~Brain()
{
	std::cout << LOWKEY << __FUNCTION__
	<< " Destructor" << called REST;
}

void	Brain::makeSound() const
{
	std::string	sound_of_cats[3] = \
	{
		"\"ts... (white noise) \"",
		"\"pip, pip... (brainwave) \"", 
		"\"tick, tock... (dr. manhattan) \""
	};

	srand(time(0));
	int n = (int) rand() % 3;
	
	// srand() debugger
	// std::cout << r << ' ' << n << std::endl;

	std::cout
	<< m_type << ": " YELL
	<< sound_of_cats[n] << REST nl;
}
