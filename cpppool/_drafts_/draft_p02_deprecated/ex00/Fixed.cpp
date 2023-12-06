/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nxu              ...   ::::::::.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#define called " called\n"

//	default constructor . way 1
/*
Fixed::Fixed()
{
	this->fixed_point_value = 0;
	std::cout << "Default constructor" << called;
}
*/

//	default constructor . way 2

Fixed::Fixed() : fixed_point_value(0)
{
	std::cout << "Default constructor" << called;
}

Fixed::Fixed(const Fixed & dummy)
{
	std::cout << "Copy constructor" << called;
	*this = dummy; // way2
	// this->fixed_point_value = dummy.getRawBits(); // way1
	
}

Fixed::~Fixed()
{
	std::cout << "Destructor" << called;
}

Fixed	& Fixed::operator = (const Fixed & dummy)
{
	std::cout << "Assignation operator" << called;
	if (this != & dummy)
		this->fixed_point_value = dummy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function" << called;
	return (this->fixed_point_value);
}

void	Fixed::setRawBits(int val)
{
	std::cout << "setRawBits member function" << called;
	this->fixed_point_value = value;
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
