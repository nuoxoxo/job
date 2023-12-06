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

#include "Dog.hpp"


// constructor . destructor

Dog::Dog() : Animal("Dog")
{
	std::cout << LOWKEY << __FUNCTION__
	<< " Constructor" << called REST;
}

Dog::~Dog()
{
	std::cout << LOWKEY << __FUNCTION__
	<< " Destructor" << called REST;
}


// copy

Dog::Dog(const Dog & dummy)
{
	*this = dummy;

	std::cout << LOWKEY << __FUNCTION__
	<< " Copy constructor" << called REST;

}


// copy assignement = 

Dog & Dog::operator = (const Dog & dummy)
{
	this->m_type = dummy.m_type;
	std::cout << LOWKEY << __FUNCTION__
	<< " Copy assignment constructor" << called REST;

	return (*this);

}


// .method()

void	Dog::makeSound() const
{
	std::string	sound_of_dogs[3] = \
	{
		"\"Woof-woof ~ \"",
		"\"Ruff-ruff ~ \"", 
		"\"Ouaf-ouaf ~ \""
	};

	srand(time(0));
	int n = (int) rand() % 3;
	// srand() debugger
	// std::cout << r << ' ' << n << std::endl;

	std::cout << m_type << ": " YELL << sound_of_dogs[n] << REST nl;
}


// getter
/*
std::string	Dog::getType() const
{
	return m_type;
}
*/
