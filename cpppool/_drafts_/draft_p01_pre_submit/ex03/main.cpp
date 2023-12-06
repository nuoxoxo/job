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
		Weapon	club = Weapon("crude spiked club");

		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");
		
		HumanB	jim("Jim");
		/*try
		{
			jim.attack();
		}
		catch (const std::overflow_error & e)
		{
			std::cout << e.what();
		}*/
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	/*	
		try-catch blocks only handle C++ exceptions. 
		segmentation faults are lower-level stuff, 
		try-catch ignores these events 
		and behaves the same as if there was no try-catch block.
	*/
	
	//	[new tests]
	
	{
		Weapon	club = Weapon("");
		HumanA	alex("Alexander", club);

		std::cout << _YELLOW_ "\nNew Test 1. \n" _REST_ ;
		alex.attack();
		club.setType("ice-cream");
		alex.attack();
	}
	{
		Weapon	club = Weapon("");
		HumanB	benji("Benjamin");

		std::cout << _YELLOW_ "\nNew Test 2. \n" _REST_ ;
		benji.setWeapon(club);
		benji.attack();
		club.setType("pack of macarons");
		benji.attack();
	}

}
