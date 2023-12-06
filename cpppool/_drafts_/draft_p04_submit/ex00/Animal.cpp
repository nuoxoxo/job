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

#include "Animal.hpp"

// canon

Animal::Animal() : m_type("(an animal)")
{
	print_canon(std::string(__FUNCTION__), "Constructor");
}

Animal::~Animal()
{
	print_canon(std::string(__FUNCTION__), "Destructor");
}

Animal::Animal(const Animal & dummy)
{
	*this = dummy;

	print_canon(std::string(__FUNCTION__), "Copy constructor");

}

Animal & Animal::operator = (const Animal & dummy)
{
	print_canon(std::string(__FUNCTION__), "Copy assignment constructor");
	
	this->m_type = dummy.m_type;
	return (*this);

}


// param constructor

Animal::Animal(std::string type) : m_type(type)
{
	print_canon(std::string(__FUNCTION__), "Parameter Constructor");

}


// method

void	Animal::makeSound() const
{
	std::cout
	<< m_type << ": " YELL "\"Pet sounds ~ \" " REST nl;
}


// getter

std::string	Animal::getType() const
{
	print_canon(m_type + ":", std::string(__FUNCTION__));

	return m_type;
}
