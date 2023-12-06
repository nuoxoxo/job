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

# include "RobotomyRequestForm.hpp"


// default
RobotomyRequestForm::RobotomyRequestForm() :
	AForm("(a piece of robotomy request)", G_RRSIGN, G_RREXEC),
	m_target("(a target)") {}

RobotomyRequestForm::~RobotomyRequestForm() {}


/// default copy constr
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & dummy) :
	AForm("(a piece of robotomy request)", G_RRSIGN, G_RREXEC),
	m_target(dummy.m_target)
{
	*this = dummy;
}


// operatr =
RobotomyRequestForm & RobotomyRequestForm::operator = (RobotomyRequestForm const & dummy)
{
	// AForm::operator = dummy;
	AForm::operator = (dummy);

	return (*this);
}


// param constr
RobotomyRequestForm::RobotomyRequestForm(std::string const & tar) :
	AForm("(a piece of robotomy request)", G_RRSIGN, G_RREXEC),
	m_target(tar) {}


// ostream overloaded (2)

std::ostream & operator << (std::ostream & ostream, RobotomyRequestForm const & form)
{
	operator << (ostream, (AForm const &) form);
	
	/*
	ostream
	<< "RobotomyRequestForm: " YELL << form.getName() << RESET nl
	<< "Stat: "
	<< (form.getIsSigned() ? GREEN "signed" : RED "not signed")
	<< RESET nl

	<< "min to sign: " CYAN << form.getGradeRequiredSign() << RESET nl
	<< "min to exec: " CYAN << form.getGradeRequiredExec() << RESET nl2;
	*/

	return (ostream);
}

std::ostream & operator << (std::ostream & ostream, RobotomyRequestForm const * form)
{
	operator << (ostream, (AForm const *) form);
	
	/*
	ostream
	<< "RobotomyRequestForm: " YELL << form->getName() << RESET nl
	<< "Stat: "
	<< (form->getIsSigned() ? GREEN "signed" : RED "not signed")
	<< RESET nl
	
	<< "min to sign: " CYAN << form->getGradeRequiredSign() << RESET nl
	<< "min to exec: " CYAN << form->getGradeRequiredExec() << RESET;
	*/

	return (ostream);
}


//	method

void	RobotomyRequestForm::execute(Bureaucrat const & undertaker) const
{
	AForm::execute(undertaker); // exception handler

	srand(time(0));
	std::cout
	<< "drilling noises: " CYAN "BzzzZzzzZzzzzzzzzzzzz..." RESET nl2;
	
	if ((int) rand() % 2)
	{
		std::cout << "target " YELL << m_target << RESET " robotomized" TICK nl2;
		return ;
	}
	std::cout
	<< "target " YELL << m_target << RESET " robotomy failed" CROSS nl
	<< RED"(...look at all this blood, yuck!)"RESET nl2;
}

