/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/12 07:50:04 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include "iostream"
# define called " called\n"


class	Fixed
{

private:
	int			m_fixed_point_value;
	static const int	m_fractional_bits = 8;

public:
	// Canon
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed &);

	// Overlord
	Fixed	& operator = (const Fixed &);	

public:
	// Getter Setter
	void	setRawBits( int const raw );
	int	getRawBits( void ) const;

};

#endif

// Original Note 1

/*
Fixed point numbers:
• Definition:
	◦ a specific number of bits or digits is reserved for the Interger
	◦ a specific number of bits reserved for the Fractional part
*/

// Original Note 2

/*
""" ex00
the class will represent *fixed point numbers:
	• Private members:
		◦ An integer to store the fixed point value. --- > *fpv
		◦ A static constant integer to store the number of fractional bits
		└─── it will always be the 8 --- >  *num of bits
	• Public members:
		◦ A default constructor to init `fpv` to 0. // TODO . in methods
		◦ A destructor.  // ~
		◦ A copy constructor. // fixed(fixed const& )
		◦ An assignation operator overload. --- > &op = (fixed const&)
		◦ member function (1)
		int getRawBits( void ) const; 
			- returns the raw value of the fixed point value.
		◦ member function (2)
		void setRawBits( int const raw ); 
			- it sets the raw value of the fixed point value.
"""
*/
