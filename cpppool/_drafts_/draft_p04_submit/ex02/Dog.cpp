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

// canon

Dog::Dog() : PureVirtualAnimal("(a dog)")
{
	// print_canon(std::string(__FUNCTION__), "Constructor");

	m_brain = new Brain(); // added Brain
}

Dog::~Dog()
{
	// print_canon(std::string(__FUNCTION__), "Destructor");

	delete m_brain; // added Brain
}


// copy

Dog::Dog(const Dog & dummy)
{
	*this = dummy;

	print_canon(std::string(__FUNCTION__), "Copy constructor");

}


// copy assignement = 

Dog & Dog::operator = (const Dog & dummy)
{
	print_canon(std::string(__FUNCTION__), "Copy assignment constructor");
	
	m_brain = new Brain(*dummy.m_brain); // added Brain

	return (*this);

}


// method

Brain	*Dog::brain() const
{
	return m_brain;
}

void	Dog::makeSound() const
{
	std::string	sound_of_dogs[3] = \
	{
		"\"Woof-woof ~ \"",
		"\"Ruff-ruff ~ \"", 
		"\"Ouaf-ouaf ~ \""
	};

	int n = (int) rand() % 3;

	// srand() debugger
	// std::cout << r << ' ' << n << std::endl;

	std::cout << m_type << ": " YELL << sound_of_dogs[n] << REST nl;
}


