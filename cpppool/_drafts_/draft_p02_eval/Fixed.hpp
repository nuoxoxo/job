/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/12 08:26:29 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include "iostream"
# include "cassert"
# include "cmath"

# define called " called\n"
# define inside "\ninside "
# define nl2 " \n\n"
# define nl " \n"
// colors
# define CYAN	"\x1b[36m"
// # define YELL	"\x1b[33;40m"
# define YELL	"\033[0;33m"
# define REST	"\x1b[0m"
# define GREEN	"\x1b[32m"
# define RED	"\x1b[31m"
# define PASS	GREEN "passed" REST
# define FAIL	RED "failed" REST

class	Fixed
{

static const int	m_number_of_fractional_bits = 8;
int			m_fixed_point_value;

public:
	// Canon
	Fixed();
	~Fixed();
	Fixed(const Fixed &);
	
	// Overload
	Fixed & operator = (const Fixed &);
	Fixed(const float);
	Fixed(const int);

	// Coverter
	float	toFloat() const ;
	int		toInt() const ;

	// Getter Setter
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	////		above: part 1
	////		below: part 2

	// Arithmetic Ops
	Fixed	operator + (const Fixed &) const ;
	Fixed	operator - (const Fixed &) const ;
	Fixed	operator * (const Fixed &) const ;
	Fixed	operator / (const Fixed &) const ;

	// Post ++/--
	Fixed	operator ++ (int);
	Fixed	operator -- (int);
	
	// Pre ++/--
	Fixed	& operator ++ (void);
	Fixed	& operator -- (void);

	// Comparison Ops
	bool	operator > (const Fixed &) const ;
	bool	operator < (const Fixed &) const ;
	bool	operator >= (const Fixed &) const ;
	bool	operator <= (const Fixed &) const ;
	bool	operator == (const Fixed &) const ;
	bool	operator != (const Fixed &) const ;


	//	std::minmax, the naive simulation of
	//		1) take ref on 2 fpv 
	//		2) return a ref of the -er one

	static	Fixed & min(Fixed &, Fixed &);
	static	Fixed & max(Fixed &, Fixed &);


	//	minmax() overloaded
	//		1) take ref on 2 const fpv
	//		2) return ref of the -er one

	static const Fixed & min(const Fixed &, const Fixed &);
	static const Fixed & max(const Fixed &, const Fixed &);
};

std::ostream & operator << (std::ostream &, const Fixed &);


// printing


/*
-	Add public static member functions overloads as follows

•	The static member function 'min' 
	
	-	takes references on two fixed point values 
		returns a reference to the smallest value
	-	an overload that takes references on 
		two constant fixed point values 
		returns a reference to the smallest constant value.

•	The static member function 'max'

	-	takes references on two fixed point values 
		returns a reference to the biggest value
	-	an overload that takes references on 
		two constant fixed point values 
		returns a reference to the biggest constant value.
*/

#endif
