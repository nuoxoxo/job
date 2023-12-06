/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   {}.hpp                                             :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/16 14:31:58 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "_Cpp05_.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{

// nothing private.

public:
	
	// canon

	Intern(); // confirmed
	~Intern(); // confirmed
	Intern(const Intern & ); // confirmed
	Intern & operator = (const Intern & ); // confirmed

	AForm * makeForm(const std::string & form_name, const std::string & target_name); // no const


};


// No ostream overload.

/*std::ostream & operator << (std::ostream &, Intern const & );
std::ostream & operator << (std::ostream &, Intern const * );
*/


#endif
