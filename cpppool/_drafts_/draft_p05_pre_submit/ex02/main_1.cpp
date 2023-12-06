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

int	main()
{
	int	count = 0;
	
	{
		AForm		*pardon = new RobotomyRequestForm("Brigitte Fontaine");
		Bureaucrat	*b = new Bureaucrat("Brigitte Fontaine", G_RRSIGN);

		std::cout << pardon << b;
		
		b->signForm(*pardon);
		b->executeForm(*pardon);
		
		delete pardon;
		delete b;
	}
	
	print_ending(++count, " - { Robotomy } - signing pardon, can sign, cannot execute");
	
	{
		AForm		*pardon = new RobotomyRequestForm("Alain Bashung");
		Bureaucrat	*b = new Bureaucrat("Alain Bashung", G_RREXEC);

		std::cout << pardon << b;
		
		b->signForm(*pardon);
		b->executeForm(*pardon);
		
		delete pardon;
		delete b;
	}
	
	print_ending(++count, " - { Robotomy } - signing pardon, signed & executed");	
	
	{
		AForm		*pardon = new RobotomyRequestForm("AS Byatt");
		Bureaucrat	*A = new Bureaucrat("Pamuk", G_RRSIGN);
		Bureaucrat	*B = new Bureaucrat("Camus", G_RREXEC);

		std::cout << pardon << A << B << nl;
		
		A->signForm(*pardon);
		A->executeForm(*pardon);
		
		std::cout << pardon;

		B->executeForm(*pardon);
		
		delete pardon;
		delete A;
		delete B;
	}
	
	print_ending(++count, " - { Robotomy } - I sign but cannot exec. Someone executes for me");
}
