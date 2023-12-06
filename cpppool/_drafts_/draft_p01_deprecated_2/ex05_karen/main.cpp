/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By: nuo <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuo               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nuo              ...   ::::::::.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main()
{
	Karen		Roberto;

	std::cout << std::endl;
	Roberto.complain("debug");
	Roberto.complain("info");
	Roberto.complain("warning");
	Roberto.complain("error");
	Roberto.complain("");
	Roberto.complain("john conway");
	Roberto.complain("terry davis");
	Roberto.complain("bjarne stroustrup");
}
