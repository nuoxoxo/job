/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/09 14:55:26 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "iostream"
# include "string"
# include "ClapTrap.hpp"


class	FragTrap : virtual public ClapTrap // added virtual
{

private:
	const static std::string		m_trait;

public:

	//	Canon

	FragTrap();
	~FragTrap();
	FragTrap(FragTrap const &);
	FragTrap & operator = (FragTrap const &);

	//	Overload

	FragTrap(std::string);

	//	New talent

	void    highFivesGuys();

};

std::string     get_input(std::string const);
void	        lowercase_str(std::string &);
void            lowercase_char(char &);


#endif
