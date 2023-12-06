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

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "_Cpp05_.hpp" // incl. fstream
# include "AForm.hpp"

# define G_SCSIGN 145
# define G_SCEXEC 137

# define TREE_UP	" ^  ^  ^   ^   ^  ^   ^  ^  ^   ^  ^   ^  ^  ^   ^   ^   ^  ^ \n"
# define TREE_DOWN "/|\\/|\\/|\\ /|\\ /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ /\\|\\/|\\/|\\ /|\\ /|\\ /|\\/|\\ \n"
# define FOREST "\n \
   ad88                                                     \n \
  d8\"                                                ,d     \n \
  88                                                 88     \n \
MM88MMM ,adPPYba,  8b,dPPYba,  ,adPPYba, ,adPPYba, MM88MMM  \n \
  88   a8\"     \"8a 88P'   \"Y8 a8P_____88 I8[    \"\"   88     \n \
  88   8b       d8 88         8PP\"\"\"\"\"\"\"  `\"Yxba,    88     \n \
  88   \"8a,   ,a8\" 88         \"8b,   ,aa aa    ]8I   88,    \n \
  88    `\"YbbdP\"'  88          `\"Ybbd8\"' `\"YbbdP\"'   \"Y888  " nl2;


class	ShrubberyCreationForm : public AForm
{

private:

	ShrubberyCreationForm();
	const std::string	m_target;	


public:

	// canon
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	ShrubberyCreationForm & operator = (ShrubberyCreationForm const & );

	// method
	void	execute(Bureaucrat const &) const;
	void	execute_way_1(void) const;
	void	execute_way_2(void) const;

};

std::ostream & operator << ( std::ostream &, AForm const &);
std::ostream & operator << ( std::ostream &, AForm const *);

void	print_ascii_trees(int);

#endif
