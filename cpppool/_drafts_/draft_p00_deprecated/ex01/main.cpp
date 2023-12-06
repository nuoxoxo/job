/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By:  nuxu <marvin@42.fr>                       ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuxu              ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nuxu             ...   ::::::::.fi       */
/*                                                                            */
/* ****************************************************************** nxu *** */

#include "Phonebook.hpp"

static void	lowercase_str(std::string &);
static void	lowercase_char(char &) ;

int	main()
{
	std::string		input;
	Phonebook		P;

	std::cout << DELIM << NL2 << ONAIR << USAGE << SKIP_PROMPT;
	while (!std::cin.eof())
	{
		std::cout << "➜ ";
		std::getline(std::cin, input);
		lowercase_str(input);
		P.parse_input(input);

		//	Switch between ADD, SEARCH & EXIT

		if (input == "add")
		{
			P.add();
			std::cout << "Contact added successfully! \n";
		}
		else if (input == "search")
		{
			P.search();
		}
		else if (input == "exit")
		{
			std::cout << "➜ \n➜ All contacts will be lost forever. \n";
			std::cout << "➜ Goodbye and have a nice day." << SKIP_PROMPT;
			P.collect_garbage();
			break ;
		}
		else
		{
			continue ;
		}
	}
}

static void	lowercase_str(std::string& s)
{
	int		i;

	i = -1;
	while (++i < (int) s.length())
	{
		lowercase_char(s[i]);
	}
}

static void	lowercase_char(char & c)
{
	c = std::tolower(c);
}
