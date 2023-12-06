/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/12 09:22:28 by nuxu             ###   ########.fr       */
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


// Overloading ` << ` for case float(n)

std::ostream & operator << (std::ostream & stream, Fixed const & fixed_number)
{
	// To debug, uncomment trailing part
	stream << fixed_number.toFloat();// << YELL " " << __FUNCTION__ << REST;

	return stream;
}


// Overloading ` = ` 

Fixed	& Fixed::operator = (const Fixed & dummy)
{
	std::cout << "Copy assignment operator" << called;

	m_fixed_point_value = dummy.getRawBits();
	
	return (*this);
}


// Converter 

float	Fixed::toFloat(void) const
{
	/*// debugger starts
	std::cout << CYAN nl << __FUNCTION__ <<  REST nl;
	
	std::cout << m_fixed_point_value;
	std::cout << YELL " (" << (m_fixed_point_value >> 8) << " << 8)" REST << nl;
	
	std::cout << " / " << nl;
	
	std::cout << (1 << 8);
	std::cout << CYAN " (1 << 8)" REST << nl;

	std::cout << " = " << nl;
	std::cout << ((float)m_fixed_point_value / (1 << 8)) << nl2;
	// debugger ends
	*/

	return (float) m_fixed_point_value / (1 << m_number_of_fractional_bits);
}

int	Fixed::toInt(void) const
{
	/*// debugger starts
	std::cout << CYAN nl << __FUNCTION__ << REST nl;
	
	std::cout << m_fixed_point_value;
	std::cout << YELL " (" << (m_fixed_point_value >> 8) << " << 8)" REST << nl;
	
	std::cout << " >> " << nl;
	
	std::cout << m_number_of_fractional_bits;
	std::cout << CYAN " (number of fractional bits)" REST << nl;

	std::cout << " = " << nl;
	std::cout << ((m_fixed_point_value) >> (m_number_of_fractional_bits)) << nl2;
	// debugger ends
	*/

	return (m_fixed_point_value) >> (m_number_of_fractional_bits);
}


// Getters . Setters

int	Fixed::getRawBits(void) const
{
	// std::cout << __FUNCTION__ << " member function" << called;
	// silenced above line to match output

	return (this->m_fixed_point_value);
}

void	Fixed::setRawBits(int const val)
{
	// std::cout << __FUNCTION__ << " member function" << called;
	// silenced above line to match output

	m_fixed_point_value = val;
}


// Constructors

Fixed::Fixed(const int x)
{
	std::cout << "Int constructor" << called;
	// silenced above line to match output
	
	// test //
	/*std::cout << YELL inside REST << __FUNCTION__ << nl;
	std::cout << CYAN "const Int x is " REST << x << nl;
	std::cout << CYAN "this->m_number_of_fractional_bits : " REST;
	std::cout << this->m_number_of_fractional_bits << nl;
	std::cout << CYAN "x << (this->m_number_of_fractional_bits) : " REST;
	std::cout << (x << this->m_number_of_fractional_bits) << nl;
	std::cout << CYAN "x << (Fixed::m_number_of_fractional_bits) : " REST;
	std::cout << (x << Fixed::m_number_of_fractional_bits) << nl2;
	*/// end //

	m_fixed_point_value = (x << m_number_of_fractional_bits);
}

Fixed::Fixed(const float x)
{
	std::cout << "Float constructor" << called;
	// silenced above line to match output
	
	/*// debugging //
	std::cout << YELL inside REST << __FUNCTION__ << nl;
	std::cout << CYAN "const Float x is " REST << x << nl;
	std::cout << CYAN "1 << 8 : " REST << (1 << 8) << nl;
	std::cout << CYAN "x * 256 : " REST << (float) x * 256 << nl;
	std::cout << CYAN "x * (1 << 8) : " REST << x * (1 << 8) << nl;
	std::cout << CYAN "roundf(x * (1 << 8) : " REST ;
	std::cout << std::roundf(x * (1 << 8)) << nl2;
	*/// debugging ends //

	/*// for debugging
	std::cout << CYAN nl << __FUNCTION__ << " constructor for float" REST nl;
	std::cout << x << nl ;;
	
	std::cout << " * " << nl;
	
	std::cout << (1 << 8);
	std::cout << CYAN " (1 << 8)" REST << nl;

	std::cout << " = " << nl;
	std::cout << (x * (1 << 8)) << nl;
	std::cout << " roundf= " << nl;
	std::cout << roundf(x * (1 << 8)) << nl2;
	// debugging ends
	*/

	m_fixed_point_value = roundf(x * (1 << m_number_of_fractional_bits));
}




/*
• overload the << operator 
	inserts a floating point version of the fixed point value into 
	the param output stream
*//*

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
