/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/09 14:55:42 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"


std::string const FragTrap::m_trait = "(trait: FragTrap) ";

//  Default

// FragTrap::FragTrap() : ClapTrap() 
FragTrap::FragTrap()
{
    m_name = "a_fragtrap";
    m_hitPoints = 100; // frag
    this->m_energyPoints = 100; // frag
    this->m_attackDamage = 30; // frag

    std::cout << LOWKEY << m_trait << "constructor" << called REST;
}

FragTrap::~FragTrap()
{
    std::cout << LOWKEY << m_trait << ITAL << m_name << REST LOWKEY << " destructor" << called REST;
}


//  Copy

FragTrap::FragTrap(FragTrap const & other)
{
    *this = other;

    std::cout << LOWKEY << m_trait << "Copy constructor" << called REST;
}


// Copy assignment =

FragTrap & FragTrap::operator = (FragTrap const & other)
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

FragTrap::FragTrap(std::string name) : ClapTrap (name) // NEW (specs) in ex01 
{
    this->m_hitPoints = 100; // scav
    this->m_energyPoints = 50; // scav
    this->m_attackDamage = 20; // scav

    std::cout
        << LOWKEY << m_trait << ITAL << m_name << REST
        << LOWKEY " constructor" << called REST;
}


//  Game

void    FragTrap::highFivesGuys(void) // NEW in ex02
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

    std::string     input;

    // input = get_input(YELL "Let Me Show You The Wonder of HIGH FIVEEE! (Y/N): " REST);
    input = get_input(YELL "High 5, OK? (Y/N): " REST);
    lowercase_str(input);
    
    if (input == "yes" || input == "y")
    {
        std::cout << m_trait << ITAL << m_name << REST
        << " 's " GREEN "High 5 accepted. High 5 given. " REST nl;
    }
    else if (input == "no" || input == "n")
    {
        std::cout
        << m_trait << ITAL << m_name << REST
        << " 's " CYAN "High 5 denied. " nl REST
        << ITAL << m_name << REST CYAN " high fived itself. Sad. " nl REST;
    }
    else
    {
        std::cout << RED "User typed "
        << input << ". \nWatch your language, " REST
        << ITAL << m_name << REST << " said." nl;
    }
}

std::string get_input(std::string const msg)
{
    std::string input;

    while (input.empty())
	{
        if (std::cin.eof())
			exit(1);
		std::cout << msg;
		getline(std::cin, input);
		if (input == "")
			continue ;
	}
    // std::cout << "in get_input: " << input << std::endl; // show
    return (input);
}

void	lowercase_str(std::string& s)
{
	int		i;

	i = -1;
	while (++i < (int) s.length())
	{
		lowercase_char(s[i]);
	}
}

void    lowercase_char(char & c) { c = std::tolower(c); }

/*
void    FragTrap::attack(const std::string & other_name)
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
    printAttack(other_name);
    this->m_energyPoints -= 1;
}

void    FragTrap::takeDamage(unsigned int num)
{ 
    printDamage(num);

    this->m_hitPoints -= num;
    
    if (this->m_hitPoints < 1)
        std::cout << NOATTACK;
    else
        printCurrentHitPts();
}

void    FragTrap::beRepaired(unsigned int num)
{
    this->m_hitPoints += num;
    this->m_energyPoints += num - 1;

    printRepair(num);
    printCurrentHitPts();
    printCurrentEnergyPts();

}
*/


//  Getter {{ obsolete }}

/*
std::string FragTrap::getName() const
{
    return (this->m_name);
}

int FragTrap::getDama() const
{
    return (this->m_attackDamage);
}
*/

//  Printers    {{ state }}

/*
void    FragTrap::printCurrentHitPts()
{
    std::cout
        << "FragTrap " << ITAL << m_name << REST
        << CYAN " currently has " << m_hitPoints << " hit points \n" REST;
}

void    FragTrap::printCurrentEnergyPts()
{
    std::cout
        << "FragTrap " << ITAL << m_name << REST
        << CYAN " currently has " << m_energyPoints << " health \n" REST;
}
*/


//  Printers    {{ action }}

/*
void    FragTrap::printRepair(unsigned int n)
{
    std::cout
        << "FragTrap " << ITAL << m_name << REST GREEN " gets repaired, gains "
        << n - 1 << " health and " << n << " hit points \n" REST;
}

void    FragTrap::printDamage(unsigned int n)
{
    std::cout
        << "FragTrap " << ITAL << m_name << REST
        << MAG " gets hit, losing "
        << n << " points of health! \n" REST;
}

void    FragTrap::printAttack(const std::string & other_name)
{
    std::cout
        << "FragTrap " << ITAL << m_name << REST
        << YELL " attacks " REST ITAL << other_name << REST ", "
        << YELL "causing " << m_attackDamage << " points of damage! \n" REST;
}
*/