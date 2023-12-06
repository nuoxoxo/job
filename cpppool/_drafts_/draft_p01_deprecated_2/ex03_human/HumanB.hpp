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

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "string"
# include "Weapon.hpp"

class HumanB
{
	/* Type B takes no weapon, not always has a weapon. hence asterisk */

	private:

		std::string	name;
		Weapon		*weapon; // *


	public:

		HumanB(std::string name); // no weapon at hand
		virtual		~HumanB(void);

		Weapon		& getWeapon(void) const;
		void		setWeapon(Weapon &); // shouldnt be const
		//void		setWeapon(Weapon &) const;
		void		attack(void) const;
};

// ----------------8<----------[ FIXME ]------------------------

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

#endif
