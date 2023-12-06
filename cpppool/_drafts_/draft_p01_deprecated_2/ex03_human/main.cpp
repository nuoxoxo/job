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

#include "iostream"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main()
{
	//	[original tests]
	{
		Weapon		club = Weapon("crude spiked club");
		HumanA		bob("Bob", club);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon		club = Weapon("crude spiked club");
		HumanB		jim("Jim");

		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	//	[new tests]
	{
		Weapon		club = Weapon("");
		HumanA		alex("Alexander", club);

		std::cout << _yw "\nNew Test 1. \n" _rs ;
		alex.attack();
		//std::cout << "\tweapon: \"ice-cream\" \n";
		club.setType("ice-cream");
		alex.attack();
	}
	{
		Weapon		club = Weapon("");
		HumanB		benji("Benjamin");

		std::cout << _yw "\nNew Test 2. \n" _rs ;
		benji.setWeapon(club);
		benji.attack();
		club.setType("pack of macarons");
		benji.attack();
	}

}
