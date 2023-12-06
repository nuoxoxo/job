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

static void     print_ending(void) {std::cout << LOWKEY nl "(...end test)" nl2 REST;};

int main(void)
{
    {
        ScavTrap    wham("Wham!"); // ClapTrap    wham("Wham!");
        
        wham.attack("Kraftwerk");
        wham.takeDamage(1);
        wham.beRepaired(3);
        wham.guardGate();

    }
    print_ending();
    {
        ClapTrap    mrOnion("Mr. Onion");
        ScavTrap    grandma("Grandma!");
        
        mrOnion.attack(grandma.getName());
        grandma.takeDamage(mrOnion.getDama());
        grandma.beRepaired(42);
        grandma.guardGate();
    }
    print_ending();

}