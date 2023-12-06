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

	{
		AForm		*F = new ShrubberyCreationForm("Maketree");
		Bureaucrat	*G = new Bureaucrat("Glen", G_SCSIGN + 1);

		std::cout << F << G;

		G->signForm( *F );

		std::cout << F;

		G->executeForm( *F );

		delete F;
		delete G;
	}

	print_ending(++count, " - { Shrubbery } - incapable for both ");

	{
		AForm		*F = new ShrubberyCreationForm("Maketree");
		Bureaucrat	*G = new Bureaucrat("Glen", G_SCSIGN);

		std::cout << F << G;

		G->signForm( *F );

		std::cout << F;

		G->executeForm( *F );

		delete F;
		delete G;
	}

	print_ending(++count, " - { Shrubbery } - can only sign it ");

	{
		AForm		*F = new ShrubberyCreationForm("plantTrees");
		Bureaucrat	*G = new Bureaucrat("Gould", G_SCEXEC);

		std::cout << F << G;

		G->signForm( *F );

		std::cout << F;

		G->executeForm( *F );

		delete F;
		delete G;
	}

	print_ending(++count, " - { Shrubbery } - can do both ");

	{
		AForm		*F = new ShrubberyCreationForm("saveThePlanet");
		Bureaucrat	*glen = new Bureaucrat("Glen", G_SCSIGN);
		Bureaucrat	*gould = new Bureaucrat("Gould", G_SCEXEC);

		std::cout << F << glen << gould;

		glen->signForm( *F );

		std::cout << F;

		glen->executeForm( *F );

		gould->executeForm( *F );


		delete F;
		delete glen;
		delete gould;
	}

	print_ending(++count, " - { Shrubbery } - signed by one, exec by another ");
}
