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

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "_Cpp05_.hpp"
# include "AForm.hpp"

# define G_PPSIGN 25
# define G_PPEXEC 5

class	PresidentialPardonForm : public AForm
{

private:

	PresidentialPardonForm();
	const std::string	m_target; // subject not clear: "target of form"
	
public:

	// canon
	~PresidentialPardonForm();
	PresidentialPardonForm(const std::string &);
	PresidentialPardonForm(const PresidentialPardonForm &);
	PresidentialPardonForm & operator = (PresidentialPardonForm const & );

	// method
	void	execute(Bureaucrat const &) const;

};


std::ostream & operator << ( std::ostream &, AForm const &);
std::ostream & operator << ( std::ostream &, AForm const *);


#endif
