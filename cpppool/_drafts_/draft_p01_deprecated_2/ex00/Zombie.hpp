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

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "iostream"
# include "string"

class	Zombie
{
	private:
		std::string	name;
		void		label(void) const;

	public:
		Zombie(std::string name);
		virtual		~Zombie(void);
		void		announce(void) const;
		std::string	get_name(void) const;
};

Zombie		*newZombie(std::string);
void		randomChump(std::string);

# define _YELLOW_	"\x1b[33m"
# define _RED_		"\x1b[31m"
# define _GREEN_		"\x1b[32m"
# define _BLUE_		"\x1b[34m"
# define _MAG_		"\x1b[35m"
# define _CYAN_		"\x1b[36m"
# define _ITAL_		"\x1b[3m"
# define _REST_		"\x1b[0m"

#endif
