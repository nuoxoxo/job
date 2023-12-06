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

Cat::Cat() : Animal("Cat")
{
	std::cout << LOWKEY << __FUNCTION__
	<< " Constructor" << called REST;
}

Cat::Cat(const Cat & dummy)
{
	*this = dummy;

	std::cout << LOWKEY << __FUNCTION__
	<< " Copy constructor" << called REST;

}

Cat & Cat::operator = (const Cat & dummy)
{
	this->m

	std::cout << LOWKEY << __FUNCTION__
	<< " Copy assignment constructor" << called REST;

	return (*this);

}

Cat::~Cat()
{
	std::cout << LOWKEY << __FUNCTION__
	<< " Destructor" << called REST;

	delete m_brain; // added
}

// .method()

void	Cat::makeSound() const
{
	std::string	sound_of_cats[3] = \
	{
		"\"Mew ~~ \"",
		"\"Meow ~~ \"", 
		"\"Purr ~~ \""
	};

	srand(time(0));
	int n = (int) rand() % 3;
	// srand() debugger
	// std::cout << r << ' ' << n << std::endl;

	std::cout << m_type << ": " YELL << sound_of_cats[n] << REST nl;
}


