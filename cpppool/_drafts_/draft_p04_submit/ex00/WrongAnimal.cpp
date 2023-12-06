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

#include "WrongAnimal.hpp"

// constructor . destructor

WrongAnimal::WrongAnimal() : m_type("(a wrong animal)")
{
	print_canon(std::string(__FUNCTION__), "Constructor");
}

WrongAnimal::~WrongAnimal()
{
	print_canon(std::string(__FUNCTION__), "Destructor");
}

WrongAnimal::WrongAnimal(const WrongAnimal & dummy)
{
	*this = dummy;

	print_canon(std::string(__FUNCTION__), "Copy constructor");
}

WrongAnimal & WrongAnimal::operator = (const WrongAnimal & dummy)
{
	print_canon(std::string(__FUNCTION__), "Copy assignment constructor");

	this->m_type = dummy.m_type;
	return (*this);

}

WrongAnimal::WrongAnimal(std::string type) : m_type(type)
{
	print_canon(std::string(__FUNCTION__), "Parameter Constructor");
}

// method

void	WrongAnimal::makeSound() const
{
	std::cout << m_type << ": " YELL "\"Pet sounds ~ \" " REST nl;
}


// getter

std::string	WrongAnimal::getType() const
{
	print_canon(m_type + ":", std::string(__FUNCTION__));

	return m_type;
}
