/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nuo <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuo               ...    :::             */
/*   Updated: 2023/01/02 15:55:58 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}
Harl::~Harl(void) {}

void	Harl::debug(void)
{
	std::cout << _G_ << __FUNCTION__ << _L_ << _R_ << std::endl;
	std::cout << _Y_ << DEBUG_LEVEL << _R_ ;
}

void	Harl::info(void)
{
	std::cout << _G_ << __FUNCTION__ << _L_ << _R_ << std::endl;
	std::cout << _Y_ << INFO_LEVEL << _R_ ;
}

void	Harl::warning(void)
{
	std::cout << _G_ << __FUNCTION__ << _L_ << _R_ << std::endl;
	std::cout << _Y_ << WARNING_LEVEL << _R_ ;
}

void	Harl::error(void)
{
	std::cout << _G_ << __FUNCTION__ << _L_ << _R_ << std::endl;
	std::cout << _Y_ << ERROR_LEVEL << _R_ ;
}

void	Harl::complain(std::string level)
{
	if (level == "")
	{
		return ;
	}

	std::string	levels[] =
	{
		"debug", "info", "warning", "error"
	};

	void	(Harl::*modes[]) (void) = 
	{
		& Harl::debug,
		& Harl::info,
		& Harl::warning,
		& Harl::error
	};

	int i = -1;
	while (++i < 4)
	{
		if (levels[i] == level)
			(this->*modes[i])();
	}
}

/*

• "DEBUG" level: 

	"I love to get extra bacon 
	for my 7XL-double-cheese-triple-pickle-special-ketchup burger. 
	I just love it!"

• "INFO" level: 

	"I cannot believe adding extra bacon cost more money. 
	You don’t put enough! 
	If you did I would not have to ask for it!"

• "WARNING" level: 

	"I think I deserve to have some extra bacon for free. 
	I’ve been coming here for years 
	and you just started working here last month."

• "ERROR" level: 

	"This is unacceptable, 
	I want to speak to the manager now."

*/
