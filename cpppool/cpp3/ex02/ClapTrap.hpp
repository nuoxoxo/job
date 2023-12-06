/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/12 13:55:09 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include "iostream"
# include "string"
# include "cstdlib"

class	ClapTrap
{

// private: // Crucial fix: use protected

protected: // use protected in order to be accessible in children class


	const static std::string		m_trait;

	std::string		m_name;	
	int				m_hitPoints;
	int				m_energyPoints;
	int				m_attackDamage;

public:

	// Canon

	ClapTrap();
	~ClapTrap();
	ClapTrap(ClapTrap const & );
	ClapTrap & operator = (ClapTrap const & );

	// Overload

	ClapTrap(std::string);

public:

	//	Getter

	std::string		getName(void) const;
	int				getDama(void) const;

	//	Game

	void			attack(const std::string & );
	void			takeDamage(unsigned int);
	void			beRepaired(unsigned int);

	//	Printer
	
	void			printAttack(const std::string &);
	void			printRepair(unsigned int);
	void			printDamage(unsigned int);
	void			printCurrentEnergyPts();
	void			printCurrentHitPts();

};


//	colors

# define REST	"\033[0;0m"
# define ITAL	"\033[3m"

# define LOWKEY	"\033[0;2m"
# define WHITE	"\033[1;37m"
# define CYAN	"\033[0;36m"
# define YELL	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define RED	"\033[0;31m"
# define MAG	"\033[0;35m"


//	formatting

# define called " called\n"
# define inside "\ninside "
# define nl2 " \n\n"
# define nl " \n"


//	action

# define NOATTACK RED "Not enough hit points to attack \n" REST
# define NOENERGY RED "Not enough energy \n" REST


//	deprecated

// # define PASS	GREEN "passed" REST
// # define FAIL	RED "failed" REST


#endif
