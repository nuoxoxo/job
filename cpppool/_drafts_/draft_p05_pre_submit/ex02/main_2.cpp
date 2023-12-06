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
#include "ShrubberyCreationForm.hpp"

int	main()
{
	int	count = 0;
	
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
