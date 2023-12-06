/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By:  nuxu <marvin@42.fr>                       ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuxu              ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nuxu             ...   ::::::::.fi       */
/*                                                                            */
/* ****************************************************************** nxu *** */

#include "iostream"

int	main(int c, char **v)
{
	std::string	msg;
	int		i;
	int		j;

	msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (c < 2)
	{
		std::cout << msg << '\n';
		return (0);
	}
	i = 0;
	while (++i < c)
	{
		std::string	s(v[i]);

		j = -1;
		while (++j < (int) s.length())
		{
			std::cout << (char) std::toupper(s[j]);
		}
	}
	std::cout << std::endl;
	return (0);
}
