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

#ifndef FORM_HPP
# define FORM_HPP

# include "_Cpp05_.hpp"
# include "Bureaucrat.hpp"

class	Bureaucrat; // added

class	Form
{

private:

	const std::string	m_name;
	bool			m_isSigned;
	const unsigned int	m_gradeRequiredSign;
	const unsigned int	m_gradeRequiredExec;

public:
	
	// Form
	
	Form();
	~Form();
	Form(Form const &);
	Form & operator = (Form const & );
	Form(std::string, unsigned int _2sign_, unsigned int _2exec_);

	class	GradeTooHighException : public std::exception
	{
		const char * what() const throw ();
	};
	
	class	GradeTooLowException : public std::exception
	{
		const char * what() const throw ();
	};


	// Getters  // added

	const std::string &	getName() const;
	unsigned int		getGradeRequiredSign() const;
	unsigned int		getGradeRequiredExec() const;
	bool			getIsSigned() const;


	// method

	void			beSigned(const Bureaucrat &);

};


std::ostream & operator << ( std::ostream &, Form const &);
std::ostream & operator << ( std::ostream &, Form const *);


#endif
