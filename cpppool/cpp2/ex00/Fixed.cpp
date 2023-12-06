/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/12 09:20:11 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


// Canon

Fixed::Fixed() : m_fixed_point_value()
{
	std::cout << "Default constructor" << called;
}

Fixed::~Fixed()
{
	std::cout << "Destructor" << called;
}

Fixed::Fixed(const Fixed & dummy)
{
	std::cout << "Copy constructor" << called;
	*this = dummy;
}


/// Overloading =

Fixed	& Fixed::operator = (const Fixed & dummy)
{
	std::cout << "Copy assignment operator" << called;
	if (this != & dummy)
		this->m_fixed_point_value = dummy.getRawBits();
	return (*this);
}


/// Getters Setters

int	Fixed::getRawBits(void) const
{
	std::cout << __FUNCTION__ << " member function" << called;
	return (this->m_fixed_point_value);
}

void	Fixed::setRawBits(int const val)
{
	std::cout << __FUNCTION__ << " member function" << called;
	// std::cout << "setRawBits member function" << called;
	this->m_fixed_point_value = val;
}


/*
$> ./a.out
Default constructor called
Copy constructor called
Assignation operator called
// .
// └── This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Assignation operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>
*/
