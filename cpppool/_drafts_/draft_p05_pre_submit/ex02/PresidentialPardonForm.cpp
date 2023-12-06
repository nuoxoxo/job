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

# include "PresidentialPardonForm.hpp"


// default
PresidentialPardonForm::PresidentialPardonForm() :
	AForm("(a piece of presidential pardon)", G_PPSIGN, G_PPEXEC),
	m_target("(a target)") {}

PresidentialPardonForm::~PresidentialPardonForm() {}


/// default copy constr
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & dummy) :
	AForm("(a piece of presidential pardon)", G_PPSIGN, G_PPEXEC),
	m_target(dummy.m_target)
{
	*this = dummy;
}


// operatr =
PresidentialPardonForm & PresidentialPardonForm::operator = (PresidentialPardonForm const & dummy)
{
	AForm::operator = (dummy);

	return (*this);
}


// param constr
PresidentialPardonForm::PresidentialPardonForm(std::string const & tar) :
	AForm("(a piece of presidential pardon)", G_PPSIGN, G_PPEXEC),
	m_target(tar) {}


// ostream overloaded (2)

std::ostream & operator << (std::ostream & ostream, PresidentialPardonForm const & form)
{
	operator << (ostream, (AForm const &) form);
	/*
	ostream
	<< "PresidentialPardonForm: " YELL << form.getName() << RESET nl
	<< "Stat: "
	<< (form.getIsSigned() ? GREEN "signed" : RED "not signed")
	<< RESET nl

	<< "min to sign: " CYAN << form.getGradeRequiredSign() << RESET nl
	<< "min to exec: " CYAN << form.getGradeRequiredExec() << RESET nl2;
	*/
	return (ostream);
}

std::ostream & operator << (std::ostream & ostream, PresidentialPardonForm const * form)
{
	operator << (ostream, (AForm const *) form);
	/*
	ostream
	<< "PresidentialPardonForm: " YELL << form->getName() << RESET nl
	<< "Stat: "
	<< (form->getIsSigned() ? GREEN "signed" : RED "not signed")
	<< RESET nl
	
	<< "min to sign: " CYAN << form->getGradeRequiredSign() << RESET nl
	<< "min to exec: " CYAN << form->getGradeRequiredExec() << RESET;
	*/
	return (ostream);
}


//	method

void	PresidentialPardonForm::execute(Bureaucrat const & undertaker) const
{
	AForm::execute(undertaker); // handling exception really

	std::cout << m_target << YELL " has been pardoned by Zaphod Beeblebrox." TICK nl2;
}


