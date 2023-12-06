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

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "string"
# include "Weapon.hpp"

class HumanA
{
	/* Type A gets weapon from Constr., always armed. hence ampersand */

	private:

		std::string	name;
		Weapon		& weapon; // &

	public:

		HumanA(std::string name, Weapon & weapon);
		virtual		~HumanA(void);
		Weapon		& getWeapon(void) const;
		void		attack(void) const;
};

#endif

// ----------------8<----------[ TODO ]------------------------

/*

- create two classes
	- HumanA
	- HumanB
		- both have a Weapon
		- both a name
		- both an attack() function
			- a printer function
			- NAME attacks with his WEAPON_TYPE
	- HumanA and HumanB have two tiny differences
		- HumanA takes the Weapon in its constructor
			- HumanB doesn’t.
		- HumanB may not always have a Weapon
			- HumanA will ALWAYS be armed
*/
