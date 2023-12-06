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

#include "Cat.hpp"

// canon

Cat::Cat() : PureVirtualAnimal("(a cat)")
{
	// print_canon(std::string(__FUNCTION__), "Constructor");

	m_brain = new Brain(); // added Brain
}

Cat::~Cat()
{
	// print_canon(std::string(__FUNCTION__), "Destructor");

	delete m_brain; // added Brain
}


// copy

Cat::Cat(const Cat & dummy)
{
	*this = dummy;

	print_canon(std::string(__FUNCTION__), "Copy constructor");

}


// copy assignement = 

Cat & Cat::operator = (const Cat & dummy)
{
	print_canon(std::string(__FUNCTION__), "Copy assignment constructor");
	
	m_brain = new Brain(*dummy.m_brain); // added Brain

	return (*this);

}


// method

Brain	*Cat::brain() const
{
	return m_brain;
}

void	Cat::makeSound() const
{
	std::string	sound_of_cats[3] = \
	{
		"\"Mew ~~ \"",
		"\"Meow ~~ \"", 
		"\"Purr ~~ \""
	};

	int n = (int) rand() % 3;

	// srand() debugger
	// std::cout << r << ' ' << n << std::endl;

	std::cout << m_type << ": " YELL << sound_of_cats[n] << REST nl;
}


