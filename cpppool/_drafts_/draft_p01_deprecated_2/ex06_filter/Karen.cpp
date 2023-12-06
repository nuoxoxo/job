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

Karen::Karen(void) {}
Karen::~Karen(void) {}

void	Karen::debug(void)	{ std::cout << debug_level; }
void	Karen::info(void)	{ std::cout << info_level; }
void	Karen::warning(void)	{ std::cout << warning_level; }
void	Karen::error(void)	{ std::cout << error_level; }

void	Karen::complain(std::string level)
{
	bool	found;
	int		i;

	if (level == "")
		return ;

	std::string	levels[] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	void	(Karen::*modes[]) (void) =
	{
		& Karen::debug,
		& Karen::info,
		& Karen::warning,
		& Karen::error
	};

	found = false;
	for (i = 0; i < 4; ++i)
	{
		if (found)
		{
			(this->*modes[i])();
		}
		else if (!found && levels[i] == level)
		{
			(this->*modes[i])();
			found = true;
		}
	}
	if (found)
		return ;
	std::cout << insignificant << std::endl;
}

void	usage()
{
	std::cout << "\tUsage: ./karenFilter \x1b[32m" << "level \x1b[0m";
	//std::cout << "[ stuff_like_maybe_a_complain_level ] \x1b[0m";
	std::cout << std::endl;
}

/*
green	"\x1b[32m"
reset	"\x1b[0m"
*/
