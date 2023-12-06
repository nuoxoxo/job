/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/12 16:43:16 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


std::string const ScavTrap::m_trait = "(trait: ScavTrap) ";

//  Default

// ScavTrap::ScavTrap() : ClapTrap()

ScavTrap::ScavTrap() // works as well w/o 2nd half of above line
{
    m_name = "a_scavtrap";
    this->m_hitPoints = 100; // scav
    this->m_energyPoints = 50; // scav
    this->m_attackDamage = 20; // scav

    std::cout << LOWKEY << m_trait << "constructor" << called REST;
}

ScavTrap::~ScavTrap()
{
    std::cout << LOWKEY << m_trait << ITAL << m_name << REST LOWKEY << " destructor" << called REST;
}


//  Copy

ScavTrap::ScavTrap(ScavTrap const & other)
{
    *this = other;

    std::cout << LOWKEY << m_trait << "Copy constructor" << called REST;
}


// Copy assignment =

ScavTrap & ScavTrap::operator = (ScavTrap const & other)
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

ScavTrap::ScavTrap(std::string name) : ClapTrap (name) // NEW (specs) in ex01 
{
    this->m_hitPoints = 100; // scav
    this->m_energyPoints = 50; // scav
    this->m_attackDamage = 20; // scav

    std::cout
        << LOWKEY << m_trait << ITAL << m_name << REST
        << LOWKEY " constructor" << called REST;
}


//  Game

void    ScavTrap::guardGate(void) // NEW in ex01
{
    if (this->m_energyPoints < 1)
    {
        std::cout << NOENERGY;
        return ;
    }
    if (this->m_hitPoints < 1)
    {
        std::cout << NOATTACK;
        return ;
    }
    std::cout
        << m_trait << ITAL << m_name << REST
        << CYAN " is assigned this role: " REST ITAL "Gate Guardian " REST nl;
}

