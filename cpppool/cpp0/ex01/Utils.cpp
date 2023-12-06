/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By:  nuxu <marvin@42.fr>                       ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuxu              ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nuxu             ...   ::::::::.fi       */
/*                                                                            */
/* ****************************************************************** nxu *** */

#include "Utils.hpp"

void	parse_input(std::string & s)
{
	if (s == "")
		return ;
    lowercase_str(s);
	std::string charset = " \t\v\r\n";
    std::size_t start = s.find_first_not_of(charset);
    std::size_t end = s.find_last_not_of(charset);
    s = start == end ? std::string(1, s[start]) : s.substr(start, end - start + 1);
}

std::string get_input(std::string const msg)
{
    std::string input;

    while (input.empty())
	{
        if (std::cin.eof())
			exit(1);
		std::cout << msg << "\n➜➜ ";
		getline(std::cin, input);
		parse_input(input);
		if (input == "")
			continue ;
	}
    // std::cout << "in get_input: " << input << std::endl; // show
    return (input);
}

void	lowercase_str(std::string& s)
{
	int		i;

	i = -1;
	while (++i < (int) s.length())
	{
		lowercase_char(s[i]);
	}
}

void    lowercase_char(char & c)
{ c = std::tolower(c); }

bool    isnumeric(std::string & s)
{ return s.find_first_not_of("0123456789") == std::string::npos; }