/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/09 14:55:26 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*			Notes			*//*

Virtual inheritance  is a C++ technique that ensures only one copy 
of a base class's member variables are inherited by grandchild derived classes.

In other words, `Vi` means that:
	there will be only 1 instance of the base A class not 2 

- (the diamond problem)
*/


#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "iostream"
# include "string"
// # include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"


/*
class	DiamondTrap : public ClapTrap 
*/// previous definition

class	DiamondTrap : public ScavTrap, public FragTrap
{

private:
	std::string m_name;
	const static std::string	m_trait; // needs redefinition
	// otherwise inherited const string memeber is not allowed.

public:

	//	Canon

	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(DiamondTrap const &);
	DiamondTrap & operator = (DiamondTrap const &);

	//	Overload

	DiamondTrap(std::string);

	//	New role

	void whoAmI();

};

#endif
