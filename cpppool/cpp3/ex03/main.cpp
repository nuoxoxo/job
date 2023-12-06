/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/09 14:55:42 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

static void print_ending(void) {std::cout<<LOWKEY nl"(...end test)"nl2 REST;};

int main(void)
{
    {
        DiamondTrap    Suntory("Suntory!"); // ScavTrap    Suntory("Suntory!");
        
        Suntory.attack("The Stone Temple Pilot");
        Suntory.takeDamage(1);
        Suntory.beRepaired(3);
        Suntory.highFivesGuys();
        // Suntory.highFivesGuys(); // too
        // Suntory.highFivesGuys(); // much
        Suntory.guardGate();

    }
    print_ending();
    {
	DiamondTrap	kurt("cobain");

	kurt.attack("Jerry");
	kurt.whoAmI();
	kurt.takeDamage(3);
	kurt.beRepaired(5);
	kurt.guardGate();
	kurt.highFivesGuys();
    }
    print_ending();
    {
        DiamondTrap	Mark;
        DiamondTrap	Luke(Mark);
        DiamondTrap	John("John");

        Mark.whoAmI();
        Mark.guardGate();
        Luke.whoAmI();
        Luke.guardGate();
        John.whoAmI();

        John.highFivesGuys();

        John.attack("Matthew");
        
	John.printCurrentEnergyPts();
        John.takeDamage(10);
        John.printCurrentEnergyPts();
        John.beRepaired(5);
        John.printCurrentEnergyPts();

    }
    print_ending();

}
