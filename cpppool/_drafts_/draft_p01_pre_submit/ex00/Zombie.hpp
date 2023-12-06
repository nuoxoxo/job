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


/* <------8<------ Zombie class ------------------> */


class	Zombie
{

private:
	std::string	name;

private:	
	void		label(void) const;

public:
	Zombie(std::string name);
	virtual ~Zombie(void);

public:
	std::string	get_name(void) const;
	void		announce(void) const;

};


Zombie		*newZombie(std::string);
void		randomChump(std::string);


/* <------8<------ Zombie colors ------------------> */

# define _YELLOW_	"\x1b[33m"
# define _GREEN_	"\x1b[32m"
# define _RED_	"\x1b[31m"
# define _BLUE_	"\x1b[34m"
# define _MAG_	"\x1b[35m"
# define _CYAN_	"\x1b[36m"
# define _ITAL_	"\x1b[3m"
# define _REST_	"\x1b[0m"


/* <------8<------ tester functions ------------------> */

void	storyline_1(void);
void	storyline_2(void);
void	storyline_3(void);
void	storyline_4(void);


#endif
