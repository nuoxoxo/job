/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   CPP08X01.hpp                                       :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/02/01 13:39:20 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP08X01_HPP
# define CPP08X01_HPP

# include "iostream"
# include "utility"
# include "vector"
# include "Span.hpp"

# define LOWKEY "\033[0;2m"
# define GREEN "\033[0;32m"
# define RESET "\033[0;0m"
# define MAX 10
# define SIZE 4

//	colors

# define ITAL	"\033[3m"
# define LOWKEY	"\033[0;2m"
# define WHITE	"\033[1;37m"
# define CYAN	"\033[0;36m"
# define YELL	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define RED	"\033[0;31m"
# define MAG	"\033[0;35m"

# define RESET	"\033[0;0m"

# define TICK	GREEN" ✓"RESET
# define CROSS	RED" ✘"RESET


//	formatting

# define called " called\n"
# define inside "\ninside "

# define nl2reset " \n\n" RESET
# define nl2 " \n\n"
# define nl " \n"

# define sspan "shortestSpan() : "
# define lspan "longestSpan() : "

void	print_pair(std::pair<int, int> p, const std::string s)
{
	std::cout
	<< CYAN << s << ": " RESET << p.first << " ~ " << p.second << nl
	<< YELL "distance: " RESET << p.second - p.first << nl2reset;
}

std::pair<int, int>	max_diff_pair(std::vector<int> v)
{
	if ((int) v.size() < 2)
		throw std::exception();
	std::sort(v.begin(), v.end());
	return (std::make_pair(v[0], v[v.size() - 1]));
}

std::pair<int, int>	min_diff_pair(std::vector<int> v)
{
	int	d, df, l, r, i;

	if ((int) v.size() < 2)
		throw std::exception();
	i = 0;
	d = 2147483647;
	std::sort(v.begin(), v.end());
	while (++i < (int) v.size())
	{
		df = v[i] - v[i - 1];
		if (d > df)
		{
			d = df;
			r = v[i];
			l = v[i - 1];
		}
	}
	return (std::make_pair(l, r));
}

#endif
