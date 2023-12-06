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
/*   ************************************************************************** */

#include "_Cpp05_.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	int	count = 0;

	{
		Intern		someRandomIntern;
		AForm		*rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat 	bureaucrat("Manu", 1);
		
		std::cout << "Hello I'm " << bureaucrat << std::endl;
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		delete rrf;
	}
	
	print_ending(++count, "provided by subject ");

	{
		Intern		I;
		AForm		*form = I.makeForm("presidential pardon", "Dr.SmashingPumpkins");
		Bureaucrat	A("Mr.ABBA", G_PPSIGN);
		Bureaucrat	Q("Ms.QUEEN", G_PPEXEC);

		std::cout << A << Q << nl << form;
		
		A.signForm(*form);
		
		std::cout << form;

		A.executeForm(*form);	
		Q.executeForm(*form);

		delete	form;
	}
	
	print_ending(++count, "one signs, the other execs. ");

	{
		Intern		I;
		AForm		*form = I.makeForm("shrubbery creation", "Mr.KISS");
		Bureaucrat	bjork("Bjork", G_SCSIGN + 1);
		Bureaucrat	jaco("Jaco", G_SCEXEC);

		if (!form)
		{
			std::cout << "There is no form \n";
			return 1;
		}
		std::cout << bjork << jaco << nl << form;
		
		bjork.signForm(*form);
		bjork.executeForm(*form);
	
		std::cout << form;

		jaco.signForm(*form);
		jaco.executeForm(*form);

		delete	form;

	}
	
	print_ending(++count, "invalid form choice, otherwise Jaco does both ");


}
