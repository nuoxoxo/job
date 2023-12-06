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
#define _y "\x1b[33m"
#define _r "\x1b[0m"
#define _c "\x1b[36m"

int	main(const int c, const char **v)
{
	std::string		s;
	std::string		*stringPTR = & s;
	std::string		&stringREF = s;

	s = "HI THIS IS BRAIN";
	std::cout << _y "\nthe address of \"HI THIS IS BRAIN\"   : " _r << \
		& s ;

	// ------------8<------------

	std::cout << _y "\nthe address pointed to by stringPTR : " _r << \
		& (*stringPTR) ;

	// ------------8<------------

	std::cout << _y "\nthe address pointed to by stringREF : " _r << \
		& stringREF << nl2;

	// ------------8<------------

	std::cout << _c "the brain : " _r << s << '\n';
	std::cout << _c "stringPTR : " _r << *stringPTR << '\n';
	std::cout << _c "stringREF : " _r << stringREF << nl2;
	(void) c;
	(void) v;
	return (0);
}
