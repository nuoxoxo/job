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

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "_Cpp05_.hpp"
# include "AForm.hpp"

# define G_RRSIGN 72
# define G_RREXEC 45

class	RobotomyRequestForm : public AForm
{

private:

	RobotomyRequestForm();
	const std::string	m_target; // subject not clear: "target of form"
	
public:

	// canon
	~RobotomyRequestForm();
	RobotomyRequestForm(const std::string &);
	RobotomyRequestForm(const RobotomyRequestForm &);
	RobotomyRequestForm & operator = (RobotomyRequestForm const & );

	// method
	void	execute(Bureaucrat const &) const;

};


std::ostream & operator << ( std::ostream &, AForm const &);
std::ostream & operator << ( std::ostream &, AForm const *);


#endif
