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

//	default, copy, destructor
Fixed::Fixed()
{ this->fixed_point_value = 0; }

Fixed::Fixed(const Fixed & dummy)
{ *this = dummy; }

Fixed::~Fixed()
{}

//	getter setter
int Fixed::getRawBits(void) const
{ return (this->fixed_point_value); }

void Fixed::setRawBits(int val)
{ this->fixed_point_value = val; }

//	assignment
Fixed	& Fixed::operator = (const Fixed & dummy)
{
	this->fixed_point_value = dummy.getRawBits(); 
	return (*this);
}

//	constructors
Fixed::Fixed(const int x)
{ this->fixed_point_value = (x << this->number_of_fractional_bits); }

Fixed::Fixed(const float x)
{ this->fixed_point_value = std::roundf(x * (1 << 8)); }

//	convertors
float	Fixed::toFloat() const
{ return (float) this->fixed_point_value / (1 << 8); }

int	Fixed::toInt() const
{ return (this->fixed_point_value) >> (this->number_of_fractional_bits); }

//	\<<\ ostream overload
std::ostream &	operator << (std::ostream & ostream, Fixed const & fx)
{ ostream << fx.toFloat(); return ostream; }

//	above: part 1
//	below: part 2

/*	arithmetic		*/

Fixed	Fixed::operator + (const Fixed & n) const
{
	return Fixed(this->toFloat() + n.toFloat());
}

Fixed	Fixed::operator - (const Fixed & n) const
{
	return Fixed(this->toFloat() - n.toFloat());
}

Fixed	Fixed::operator * (const Fixed &n) const
{
	return Fixed(this->toFloat() * n.toFloat());
}

Fixed	Fixed::operator / (const Fixed & n) const
{
	if (n.toInt() > 0)
		return Fixed(this->toFloat() / n.toFloat());
	else throw std::runtime_error("Cannot divide by zero"); // unique
}

/*	symbols		*/

bool	Fixed::operator > (Fixed const & n) const
{
	return this->fixed_point_value > n.fixed_point_value;
}

bool	Fixed::operator < (const Fixed & n) const
{
	return this->fixed_point_value < n.fixed_point_value;
}

bool	Fixed::operator >= (const Fixed & n) const
{
	return this->getRawBits() >= n.getRawBits();
}

bool	Fixed::operator <= (const Fixed & n) const
{
	return this->getRawBits() <= n.getRawBits();;
}

bool	Fixed::operator == (const Fixed & n) const
{
	return this->getRawBits() == n.getRawBits();;
}

bool	Fixed::operator != (const Fixed & n) const
{
	return !(*this == n);
}

/*	increment . decrement		*/

Fixed	& Fixed::operator ++ (void)
{
	this->fixed_point_value += 1;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed	temp(*this);

	(*this).fixed_point_value += 1;
	return (temp);
}

Fixed	& Fixed::operator -- (void)
{
	this->fixed_point_value -= 1;
	return (*this);
}

Fixed	Fixed::operator -- (int)
{
	Fixed	temp(*this);

	(*this).fixed_point_value -= 1;
	return (temp);
}

/*	min . max		*/

/*	
 *	Subject dictates: 
 *	
 *	1. /static/ member functions
 *		pass-in	: /references/ of 2 Fixeds
 *		returns : /reference/ to the smaller one
 *	
 *	2. overloads
 *		pass-in	: /references/ of 2 /constant/ Fixeds
 *		returns	: /reference/ to the smaller /constant/
 */

Fixed	& Fixed::min(Fixed & n1, Fixed & n2)
{
	if (n1.fixed_point_value < n2.fixed_point_value)
		return n1;
	return n2;
}

Fixed	& Fixed::max(Fixed & n1, Fixed & n2)
{
	if (n1.fixed_point_value > n2.fixed_point_value)
		return n1;
	return n2;
}

Fixed const & Fixed::min(const Fixed & n1, const Fixed & n2)
{
	if (n1.fixed_point_value < n2.fixed_point_value)
		return n1;
	return n2;
}

Fixed const & Fixed::max(const Fixed & n1, const Fixed & n2)
{
	if (n1.fixed_point_value > n2.fixed_point_value)
		return n1;
	return n2;
}
