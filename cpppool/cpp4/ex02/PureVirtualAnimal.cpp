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

/*
 * 
 *	everything the same as x00
 * 
 */

#include "PureVirtualAnimal.hpp"


// canon

PureVirtualAnimal::PureVirtualAnimal() : m_type("(an animal)")
{
	// print_canon(std::string(__FUNCTION__), "Constructor");
}

PureVirtualAnimal::~PureVirtualAnimal()
{
	// print_canon(std::string(__FUNCTION__), "Destructor");
}

PureVirtualAnimal::PureVirtualAnimal(const PureVirtualAnimal & dummy)
{
	*this = dummy;

	print_canon(std::string(__FUNCTION__), "Copy constructor");

}

PureVirtualAnimal & PureVirtualAnimal::operator = (const PureVirtualAnimal & dummy)
{
	this->m_type = dummy.m_type;

	print_canon(std::string(__FUNCTION__), "Copy assignment constructor");

	return (*this);

}


// param constructor

PureVirtualAnimal::PureVirtualAnimal(std::string type) : m_type(type)
{
	// print_canon(std::string(__FUNCTION__), "Parameter Constructor");

}


// method

// void	PureVirtualAnimal::makeSound() const
// {
// 	std::cout
// 	<< m_type << ": " YELL "\"Pet sounds ~ \" " REST nl;
// }


// getter

std::string	PureVirtualAnimal::getType() const
{
	// print_canon(m_type + ":", std::string(__FUNCTION__));

	return m_type;
}
