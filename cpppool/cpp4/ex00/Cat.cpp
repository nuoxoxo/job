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

// constructor . destructor

Cat::Cat() : Animal("(a cat)")
{
	print_canon(std::string(__FUNCTION__), "Constructor");
}

Cat::~Cat()
{
	print_canon(std::string(__FUNCTION__), "Destructor");
}

Cat::Cat(const Cat & dummy)
{
	*this = dummy;

	print_canon(std::string(__FUNCTION__), "Copy constructor");
}

Cat & Cat::operator = (const Cat & dummy)
{
	print_canon(std::string(__FUNCTION__), "Copy assignment constructor");
	
	this->m_type = dummy.m_type;

	return (*this);

}


// method

void	Cat::makeSound() const
{
	std::string	sound_of_cats[3] = \
	{
		"\"Mew ~~ \"",
		"\"Meow ~~ \"", 
		"\"Purr ~~ \""
	};

	std::cout << m_type << ": " YELL << sound_of_cats[(int) rand() % 3] << REST nl;
}


