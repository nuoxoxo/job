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

#include "iostream"
#include "string"

#define nl2 "\n\n" 
#define _Y_ "\x1b[33m"
#define _R_ "\x1b[0m"
#define _C_ "\x1b[36m"

int	main(const int c, const char **v)
{
	std::string		s;
	std::string		*stringPTR = & s;
	std::string		&stringREF = s;

	s = "HI THIS IS BRAIN";
	std::cout << _Y_ "\nthe address of \"HI THIS IS BRAIN\"   : " _R_ << \
		& s ;

	// ------------8<------------

	std::cout << _Y_ "\nthe address pointed to by stringPTR : " _R_ << \
		stringPTR ;

	// ------------8<------------

	std::cout << _Y_ "\nthe address pointed to by stringREF : " _R_ << \
		& stringREF << nl2;

	// ------------8<------------

	std::cout << _C_ "the brain : " _R_ << s << '\n';
	std::cout << _C_ "stringPTR : " _R_ << *stringPTR << '\n';
	std::cout << _C_ "stringREF : " _R_ << stringREF << nl2;
	(void) c;
	(void) v;
	return (0);
}
