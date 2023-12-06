/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   {{}}.hpp                                           :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/16 14:31:58 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_Cpp05_.hpp"
#include "Bureaucrat.hpp"


// canon

// const std::string	m_name;
// unsigned int		m_grade;

Bureaucrat::Bureaucrat() : m_name("(some bureaucrat)"), m_grade(150) {}
Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat & dummy) : m_name(dummy.m_name)
{
	*this = dummy;
}

Bureaucrat & Bureaucrat::operator = (Bureaucrat const & dummy )
{

	m_grade = dummy.m_grade;
	return (*this);
}

Bureaucrat::Bureaucrat(std::string s, unsigned int G)
: m_name(s), m_grade(G)
{
	if (m_grade < G_HIGH)
	{
		throw ( GradeTooHighException() );
	}
	else if (m_grade > G_LOW)
	{
		throw ( GradeTooLowException() );
	}
}


// overloading the `<<`

// std::ostream & operator << (std::ostream &, Bureaucrat const & );
// std::ostream & operator << (std::ostream &, Bureaucrat const * );

std::ostream & operator << (std::ostream & ostream, Bureaucrat const & person)
{
	ostream
	<< person.getName() <<  ", bureaucrat grade "
	<< person.getGrade() << nl;

	return (ostream);
}

std::ostream & operator << (std::ostream & ostream, Bureaucrat const * person)
{
	ostream
	<< person->getName() <<  ", bureaucrat grade "
	<< person->getGrade() << nl;

	return (ostream);
}

// getter

const std::string & Bureaucrat::getName() const
{
	return (m_name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return (m_grade);
}


// method

void	Bureaucrat::gradeUp()
{
	print_canon(std::string(__FUNCTION__), "method");
	if (--m_grade < G_HIGH)
	{
		throw ( GradeTooHighException() );
	}
}

void	Bureaucrat::gradeDown()
{
	print_canon(std::string(__FUNCTION__), "method");
	if (++m_grade > G_LOW)
	{
		throw ( GradeTooLowException() );
	}
}


// overloading the ostream

/*
class	GradeTooHighException : public std::exception {
	const char * what() const throw ();
};

class	GradeTooLowException : public std::exception {
	const char * what() const throw ();
};
*/

const char * Bureaucrat::GradeTooLowException::what() const throw ()
{
	return (CYAN "Error: Grade too low. \n" RESET);
}

const char * Bureaucrat::GradeTooHighException::what() const throw ()
{
	return (YELL "Error: Grade too high. \n" RESET)
	;
}


