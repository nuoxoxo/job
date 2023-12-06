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

#include "WrongCat.hpp"

// constructor . destructor

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	print_canon(std::string(__FUNCTION__), "Constructor");
}

WrongCat::~WrongCat()
{
	print_canon(std::string(__FUNCTION__), "Destructor");
}


// copy

WrongCat::WrongCat(const WrongCat & dummy)
{
	*this = dummy;

	print_canon(std::string(__FUNCTION__), "Copy constructor");

}


// copy assignement = 

WrongCat & WrongCat::operator = (const WrongCat & dummy)
{
	print_canon(std::string(__FUNCTION__), "Copy assignment constructor");

	this->m_type = dummy.m_type;
	return (*this);

}


// method

void	WrongCat::makeSound() const
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


