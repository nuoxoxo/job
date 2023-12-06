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

/*

""" exoo
the class will represent *fixed point numbers:
	• Private members:
		◦ An integer to store the fixed point value. --- > *fpv
		◦ A static constant integer to store the number of fractional bits
		└─── it will always be the 8 --- >  *nofb
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

#ifndef FIXED_HPP
# define FIXED_HPP

# include "iostream"

class	Fixed
{
	private:
		int			fixed_point_value;
		static const int	number_of_fractional_bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &);
		~Fixed(void);
		Fixed			& operator = (const Fixed &);
		void			setRawBits(int);
		int			getRawBits(void) const;

		// default constr to init the private `fpv`
		// a copy constr
		// destr
		// overloading the assignment operator
		// will set raw val of `fpv`
		// will return raw val of `fpv`
};

#endif
