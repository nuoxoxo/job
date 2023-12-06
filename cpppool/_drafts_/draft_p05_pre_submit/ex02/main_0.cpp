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
#include "PresidentialPardonForm.hpp"

int	main()
{
	int	count = 0;
	
	{
		AForm		*pardon = new PresidentialPardonForm("Brigitte Fontaine");
		Bureaucrat	*b = new Bureaucrat("Brigitte Fontaine", G_PPSIGN);

		std::cout << pardon << b;
		
		b->signForm(*pardon);
		b->executeForm(*pardon);
		
		delete pardon;
		delete b;
	}
	
	print_ending(++count, " - { President } - signing pardon, can sign, cannot execute");
	
	{
		AForm		*pardon = new PresidentialPardonForm("Alain Bashung");
		Bureaucrat	*b = new Bureaucrat("Alain Bashung", G_PPEXEC);

		std::cout << pardon << b;
		
		b->signForm(*pardon);
		b->executeForm(*pardon);
		
		delete pardon;
		delete b;
	}
	
	print_ending(++count, " - { President } - signing pardon, signed & executed");	
	
	{
		AForm		*pardon = new PresidentialPardonForm("AS Byatt");
		Bureaucrat	*A = new Bureaucrat("Pamuk", G_PPSIGN);
		Bureaucrat	*B = new Bureaucrat("Camus", G_PPEXEC);

		std::cout << pardon << A << B << nl;
		
		A->signForm(*pardon);
		A->executeForm(*pardon);
		
		std::cout << pardon;

		B->executeForm(*pardon);
		
		delete pardon;
		delete A;
		delete B;
	}
	
	print_ending(++count, " - { President } - I sign but cannot exec. Someone executes for me");

	
}
