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

Dog::Dog() : Animal("(a dog)")
{
	print_canon(std::string(__FUNCTION__), "Constructor");
}

Dog::~Dog()
{
	print_canon(std::string(__FUNCTION__), "Destructor");
}

Dog & Dog::operator = (const Dog & dummy)
{
	print_canon(std::string(__FUNCTION__), "Copy assignment constructor");
	
	this->m_type = dummy.m_type;
	return (*this);

}

Dog::Dog(const Dog & dummy)
{
	*this = dummy;

	print_canon(std::string(__FUNCTION__), "Copy constructor");

}

// method

void	Dog::makeSound() const
{
	std::string	sound_of_dogs[3] = \
	{
		"\"Woof-woof ~ \"",
		"\"Ruff-ruff ~ \"", 
		"\"Ouaf-ouaf ~ \""
	};

	std::cout << m_type << ": " YELL << sound_of_dogs[(int) rand() % 3] << REST nl;
}

