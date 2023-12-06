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

#include "Intern.hpp"


//	canon

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern & dummy) {*this = dummy;}
Intern & Intern::operator = (const Intern & dummy) {/* do nothing */ (void) dummy; return *this;}

AForm * Intern::makeForm(const std::string & form, const std::string & target)
{
	std::string	wordlist[3] = /* subject dictates */ {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	int	i = 3;

	while (--i > -1)
	{
		if (wordlist[i] == form)
			break ;
	}
	switch (i)
	{
		case 2:
			return ( new ShrubberyCreationForm(target) );		
		case 1:
			return ( new RobotomyRequestForm(target) );
		case 0:
			return ( new PresidentialPardonForm(target) );
		
		case -1:
			std::cout << "No such form template: " YELL << form << RESET nl;
			break;
	}
	
	return (NULL); // vs. nullptr
}
