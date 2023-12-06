/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/16 14:31:58 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "_Cpp05_.hpp"
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{

private:

	AForm();
	// put default constr here 
	// to prevent creating object w/o instance fields or methods
	
	const std::string	m_name;
	bool			m_isSigned;
	const unsigned int	m_gradeRequiredSign;
	const unsigned int	m_gradeRequiredExec;

public:

	// canon
	AForm(AForm const &);
	AForm & operator = (AForm const & );
	AForm(std::string, unsigned int _2sign_, unsigned int _2exec_);

	virtual	~AForm(); // added keyword *

	// exceptions
	class	FormUnsignedException : public std::exception
	{
		const char * what() const throw (); // added exception *
	};


	class	GradeTooHighException : public std::exception {
		const char * what() const throw ();
	};
	
	class	GradeTooLowException : public std::exception {
		const char * what() const throw ();
	};


	// getters
	const std::string &	getName() const;
	unsigned int		getGradeRequiredSign() const;
	unsigned int		getGradeRequiredExec() const;
	bool			getIsSigned() const;


	// method
	
	void		beSigned(const Bureaucrat &);
	// added virtual func
	virtual void	execute(const Bureaucrat &) const = 0;

};


std::ostream & operator << ( std::ostream &, AForm const &);
std::ostream & operator << ( std::ostream &, AForm const *);


#endif
