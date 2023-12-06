/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/12 07:58:46 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include "iostream"
# include "cmath" // added

class	Fixed
{

private:
	static const int	m_number_of_fractional_bits = 8;
	int			m_fixed_point_value;

public:
	// Canon
	Fixed();
	~Fixed();
	Fixed(const Fixed &);
	
	// Overload
	Fixed & operator = (const Fixed &);
	Fixed(const float); // added
	Fixed(const int); // added

	// Coverter
	float	toFloat( void ) const ; // added
	int		toInt(void) const ; // added 

	// Getter Setter
	int		getRawBits(void) const;
	void	setRawBits(int const);

};

std::ostream & operator << (std::ostream &, const Fixed &); // x01

# define called " called\n"
# define inside "\ninside "
# define CYAN	"\x1b[36m"
# define YELL	"\x1b[33m"
# define REST	"\x1b[0m"
# define nl2 " \n\n"
# define nl " \n"

#endif
