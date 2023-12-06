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
	private:
		std::string type;

	public:
		Weapon(std::string type);
		virtual			~Weapon(void);
		void			setType(const std::string & type); // const
		const std::string	& getType(void) const; // &
};

# define love	"[\x1b[3msic]\x1b[0m \x1b[33mnothing\x1b[0m"
# define _gn	"\x1b[32m"
# define _cn	"\x1b[36m"
# define _rs	"\x1b[0m"
# define _yw	"\x1b[33m"
# define _br	"\x1b[33;1m"

#endif

// ----------------8<----------[ TODO ]------------------------

/*

- todo a Weapon class, which has
	- a type string
	- a getType method 
		- getType returns a const reference to the type string
	- a setType method

*/
