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

#ifndef FIXED_HPP
# define FIXED_HPP

# include "iostream"
# include "cmath" // part 1

class	Fixed
{
	private:
		static const int	number_of_fractional_bits = 8;
		int			fixed_point_value;

	public:
		Fixed(void);

		Fixed(const float); // part 1
		Fixed(const int); // part 1

		Fixed(const Fixed &);
		~Fixed(void);

		Fixed			& operator = (const Fixed &);

		void			setRawBits(int);
		int			getRawBits(void) const;

		float			toFloat() const ; // part 1
		int			toInt() const ; // part 1

};

std::ostream & operator << (std::ostream &, const Fixed &); // part 1

# define cy	"\x1b[36m"
# define yell	"\x1b[33m"
# define rest	"\x1b[0m"

#endif
