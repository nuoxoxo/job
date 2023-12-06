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

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include "string"

class Weapon
{
	std::string type;

	public:
		Weapon(std::string type);
		virtual	~Weapon(void);
	
	public:
		void			setType(const std::string & type);
		const std::string&	getType(void) const; // &
};

# define _LOVE_	"[\x1b[3msic]\x1b[0m \x1b[33mnothing\x1b[0m"
# define _CYAN_	"\x1b[36m"
# define _REST_	"\x1b[0m"
# define _YELLOW_	"\x1b[33m"
# define _GREEN_	"\x1b[32m"

#endif

// ----------------8<----------[ TODO ]------------------------

/*

- todo a Weapon class, which has
	- a type string
	- a getType method 
		- getType returns a const reference to the type string
	- a setType method 
		- not const coz modifies type

*/
