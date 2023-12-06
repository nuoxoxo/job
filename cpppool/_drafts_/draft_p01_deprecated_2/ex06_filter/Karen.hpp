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

#ifndef KAREN_HPP
# define KAREN_HPP

#include "iostream"
#include "string"


enum	Levels
{
	DEBUG = 0,
	INFO,
	WARNING,
	ERROR
};


class	Karen {
	private:
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
	public:

		Karen(void);
		virtual		~Karen(void);
		void		complain(std::string);
};


void	usage(void);


//	def. all strings


#define debug_level \
"[ DEBUG ]\nI love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n\n"
#define info_level \
"[ INFO ]\nI cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n\n"
#define warning_level \
"[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming here for years and you just started working here last month.\n\n"
#define error_level \
"[ ERROR ]\nThis is unacceptable, I want to speak to the manager now.\n\n"

#define insignificant "[ Probably complaining about insignificant problems ]\n\n"

#endif
