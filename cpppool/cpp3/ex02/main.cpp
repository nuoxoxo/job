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

static void     print_ending(void) {std::cout << LOWKEY nl "(...end test)" nl2 REST;};

int main(void)
{
    {
        FragTrap    wham("Wham!"); // ScavTrap    wham("Wham!");
        
        wham.attack("Pearl Jam");
        wham.takeDamage(1);
        wham.beRepaired(3);
        wham.highFivesGuys();
        wham.highFivesGuys();
        wham.highFivesGuys();

    }
    print_ending();

}