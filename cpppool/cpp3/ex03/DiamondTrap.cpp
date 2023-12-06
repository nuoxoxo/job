/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/09 14:55:42 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

/*

In the above program, constructor of ‘Person’ is called two times. 
Destructor of ‘Person’ will also be called two times when object ‘ta1’ is destructed. 
So object ‘ta1’ has two copies of all members of ‘Person’, this causes ambiguities. 
The solution to this problem is ‘virtual’ keyword. 

We make the classes ‘Faculty’ and ‘Student’ as virtual base classes 
to avoid two copies of ‘Person’ in ‘TA’ class. 

*/

std::string const DiamondTrap::m_trait = "(trait: DiamondTrap) ";

//  Default

// DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap() // DONE

DiamondTrap::DiamondTrap() // works as well w/o 2nd half of above line
{
    m_name = "a_diamondtrap";
    ClapTrap::m_name = m_name + "_clap_name";
    
    m_energyPoints = 50; // scav -> reset to match older assignement
    // m_hitPoints = 100; // frag (more recent)
    // m_attackDamage = 20; // frag (more recent)

    std::cout << LOWKEY << m_trait << "constructor" << called REST;
}

DiamondTrap::~DiamondTrap() // DONE
{
    std::cout << LOWKEY << m_trait << ITAL << m_name << REST LOWKEY << " destructor" << called REST;
}


//  Copy

DiamondTrap::DiamondTrap(DiamondTrap const & other) // DONE
{
    *this = other;

    std::cout << LOWKEY << m_trait << "Copy constructor" << called REST;
}


// Copy assignment =

DiamondTrap & DiamondTrap::operator = (DiamondTrap const & other) // DONE
{
    std::cout << LOWKEY << m_trait << "Copy assignment operator" << called REST;
    
    if (this == & other)
        return *this;
    
    this->m_name = other.m_name;
    this->m_hitPoints = other.m_hitPoints;
    this->m_energyPoints = other.m_energyPoints;
    this->m_attackDamage = other.m_attackDamage;

    return (*this);
}


//  Constructor overload

DiamondTrap::DiamondTrap(std::string name) : m_name(name) // DONE
{
    // m_name = "a_diamondtrap";
    ClapTrap::m_name = m_name + "_clap_name";
    
    m_energyPoints = 50;

    std::cout
        << LOWKEY << m_trait << ITAL << m_name << REST
        << LOWKEY " constructor" << called REST;
}


//  Game


void DiamondTrap::whoAmI() // DONE
{
	std::cout << "DmndTrap name:\t" << m_name << nl
	<< "ClapTrap name:\t" << this->ClapTrap::m_name << nl;
}

