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
#define inside "\ninside "
#define nl2 " \n\n"
#define nl " \n"

/*

""" exo1
do the following stuff
	• constructor 1
		- takes a constant \integer\ as a parameter 
		- converts it to the correspondant fixed(8) point value
		- The fractional bits value is initialized like in ex00

	• constructor 2
		- takes a constant \floating point\ as a parameter 
		- converts it to the correspondant fixed(8) point value 
		- The fractional bits value is initialized like in ex00

	• member 1
		- proto :	float toFloat( void ) const;
		- converts the fixed point value to a floating point value.

	• member 2
		- proto :	int toInt( void ) const;
		- converts the fixed point value to an integer value.

	• overload the « operator 
		- inserts a floating point version of the fpv into 
		the param output stream.
"""

*/

Fixed::Fixed()
{
	this->fixed_point_value = 0;
	std::cout << "Default constructor" << called;
}

Fixed::Fixed(const int x)
{
	std::cout << "Int constructor" << called;
	// test
	std::cout << yell inside rest << __FUNCTION__ << nl;
	std::cout << cy "const Int x is " rest << x << nl;
	std::cout << cy "this->number_of_fractional_bits : " rest;
	std::cout << this->number_of_fractional_bits << nl;
	std::cout << cy "x << (this->number_of_fractional_bits) : " rest;
	std::cout << (x << this->number_of_fractional_bits) << nl;
	std::cout << cy "x << (Fixed::number_of_fractional_bits) : " rest;
	std::cout << (x << Fixed::number_of_fractional_bits) << nl2;
	// end //
	this->fixed_point_value = (x << this->number_of_fractional_bits);
}

Fixed::Fixed(const float x)
{
	std::cout << "Float constructor" << called;
	// test
	std::cout << yell inside rest << __FUNCTION__ << nl;
	std::cout << cy "const Float x is " rest << x << nl;
	std::cout << cy "1 << 8 : " rest << (1 << 8) << nl;
	std::cout << cy "x * 256 : " rest << (float) x * 256 << nl;
	std::cout << cy "x * (1 << 8) : " rest << x * (1 << 8) << nl;
	std::cout << cy "roundf(x * (1 << 8) : " rest ;
	std::cout << std::roundf(x*(1 << 8)) << nl2;
	// end //
	this->fixed_point_value = std::roundf(x * (1 << 8));
}

Fixed::Fixed(const Fixed & dummy)
{
	std::cout << "Copy constructor" << called;
	*this = dummy;
	// this->fixed_point_value = dummy.getRawBits(); // way1
}

Fixed::~Fixed()
{
	std::cout << "Destructor" << called;
}

Fixed	& Fixed::operator = (const Fixed & dummy)
{
	std::cout << "Assignation operator" << called;
	this->fixed_point_value = dummy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	// silenced to match output
	//std::cout << "getRawBits member function" << called;
	return (this->fixed_point_value);
}

void	Fixed::setRawBits(int val)
{
	// silenced to match output
	//std::cout << "setRawBits member function" << called;
	this->fixed_point_value = val;
}

//	new . 2Float . 2Int . overload ostrm

float	Fixed::toFloat() const
{
	return (float) this->fixed_point_value / (1 << 8);
}

int	Fixed::toInt() const
{
	return (this->fixed_point_value) >> (this->number_of_fractional_bits);
}

std::ostream &	operator << (std::ostream & ostream, Fixed const & fx)
{
	ostream << fx.toFloat();
	return ostream;
}

