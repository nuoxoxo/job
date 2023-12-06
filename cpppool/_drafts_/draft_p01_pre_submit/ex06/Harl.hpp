/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nuo <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuo               ...    :::             */
/*   Updated: 2023/01/02 15:44:11 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Harl_HPP
# define Harl_HPP

# include "iostream"
# include "string"


class	Harl
{

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:
	Harl(void);
	virtual	~Harl(void);
	void	complain(std::string);

};


void	uppercase_str(std::string &);
void	uppercase_char(char &) ;
void	usage(void);


//	def. all strings

/* 
# define DEBUG_LEVEL "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it! \n\n"*/
# define DEBUG_LEVEL "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do! \n\n"
/*
# define INFO_LEVEL "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it! \n\n"*/
# define INFO_LEVEL "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more! \n\n"
/*
# define WARNING_LEVEL "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month. \n\n"*/
# define WARNING_LEVEL "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month. \n\n"
/*
# define ERROR_LEVEL "This is unacceptable, I want to speak to the manager now. \n\n"*/
# define ERROR_LEVEL "This is unacceptable! I want to speak to the manager now. \n\n"

#define INSIGNIFICANT "[ Probably complaining about insignificant problems ]\n\n"

//	def. colors

# define _Y_ "\x1b[33m"
# define _G_ "\x1b[32;1m"
# define _I_ "\x1b[3m"
# define _R_ "\x1b[0m"
# define _L_ " level"


#endif
