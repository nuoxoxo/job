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

Animal::Animal() : m_type("_an_animal_")
{
	std::cout
	<< LOWKEY << __FUNCTION__
	<< " Constructor" << called REST;
}

Animal::~Animal()
{
	std::cout
	<< LOWKEY << __FUNCTION__
	<< " Destructor" << called REST;
}

Animal::Animal(const Animal & dummy)
{
	*this = dummy;

	std::cout
	<< LOWKEY << __FUNCTION__
	<< " Copy constructor" << called REST;

}

Animal & Animal::operator = (const Animal & dummy)
{
	this->m_type = dummy.m_type;

	std::cout
	<< LOWKEY << __FUNCTION__
	<< " Copy assignment constructor" << called REST;

	return (*this);

}

// param constructor

Animal::Animal(std::string type) : m_type(type)
{
	std::cout
	<< LOWKEY << __FUNCTION__
	<< " Constructor (overloaded)" << called REST;

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
	std::cout
	<< LOWKEY << m_type << ": " << __FUNCTION__ << called REST;

	return m_type;
}


