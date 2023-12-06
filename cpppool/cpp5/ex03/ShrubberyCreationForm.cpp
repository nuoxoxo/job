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

# include "ShrubberyCreationForm.hpp"

// default
ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("(a piece of robotomy request)", G_SCSIGN, G_SCEXEC),
	m_target("(a target)") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


/// default copy constr
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & dummy) :
	AForm("(a request for some shrubbery)", G_SCSIGN, G_SCEXEC),
	m_target(dummy.m_target)
{
	*this = dummy;
}


// operatr =
ShrubberyCreationForm & ShrubberyCreationForm::operator = (ShrubberyCreationForm const & dummy)
{
	// AForm::operator = dummy;
	AForm::operator = (dummy);

	return (*this);
}


// param constr
ShrubberyCreationForm::ShrubberyCreationForm(std::string const & tar) :
	AForm("(a request for some shrubbery)", G_SCSIGN, G_SCEXEC),
	m_target(tar) {}


// ostream overloaded (2)

std::ostream & operator << (std::ostream & ostream, ShrubberyCreationForm const & form)
{
	operator << (ostream, (AForm const &) form);
	
	/*
	ostream
	<< "ShrubberyCreationForm: " YELL << form.getName() << RESET nl
	<< "Stat: "
	<< (form.getIsSigned() ? GREEN "signed" : RED "not signed")
	<< RESET nl

	<< "min to sign: " CYAN << form.getGradeRequiredSign() << RESET nl
	<< "min to exec: " CYAN << form.getGradeRequiredExec() << RESET nl2;
	*/

	return (ostream);
}

std::ostream & operator << (std::ostream & ostream, ShrubberyCreationForm const * form)
{
	operator << (ostream, (AForm const *) form);
	
	/*
	ostream
	<< "ShrubberyCreationForm: " YELL << form->getName() << RESET nl
	<< "Stat: "
	<< (form->getIsSigned() ? GREEN "signed" : RED "not signed")
	<< RESET nl
	
	<< "min to sign: " CYAN << form->getGradeRequiredSign() << RESET nl
	<< "min to exec: " CYAN << form->getGradeRequiredExec() << RESET;
	*/

	return (ostream);
}


//	method

void	ShrubberyCreationForm::execute(Bureaucrat const & undertaker) const
{
	AForm::execute(undertaker); // exception handler

	// execute_way_1();
	execute_way_2();

	return ;
}

//	ofstream - 2 ways

void	ShrubberyCreationForm::execute_way_1(void) const
{
	std::string	trees = TREE_UP TREE_DOWN TREE_DOWN TREE_DOWN;
	std::string	filename = m_target + "_shrubbery";
	std::ofstream	ofs(filename.c_str());
	
	for (int i = 3; i; --i)
	{
		ofs << TREE_UP TREE_DOWN TREE_DOWN TREE_DOWN;
		ofs << FOREST;
	}
	ofs << TREE_UP TREE_DOWN TREE_DOWN TREE_DOWN;
	ofs << std::endl;

}

void	ShrubberyCreationForm::execute_way_2(void) const
{
	std::fstream	fs;
	std::string	trees = TREE_UP TREE_DOWN TREE_DOWN TREE_DOWN;
	std::string	filename = m_target + "_shrubbery";

	fs.open(filename.c_str(), std::fstream::out); // out :: outfile :: out is open for write
	
	for (int i = 3; i; --i)
	{
		fs << TREE_UP TREE_DOWN TREE_DOWN TREE_DOWN;
		fs << FOREST;
	}
	fs << TREE_UP TREE_DOWN TREE_DOWN TREE_DOWN;
	fs << std::endl;
}


/* **************** Below: Deprecated **************** */


/*// helper

static void	print_trees(void)
{
	std::cout << TREE_UP TREE_DOWN TREE_DOWN TREE_DOWN;
}

void	print_ascii_trees(int n)
{
	std::string	s;

	s = "\n \
   ad88                                                     \n \
  d8\"                                                ,d     \n \
  88                                                 88     \n \
MM88MMM ,adPPYba,  8b,dPPYba,  ,adPPYba, ,adPPYba, MM88MMM  \n \
  88   a8\"     \"8a 88P'   \"Y8 a8P_____88 I8[    \"\"   88     \n \
  88   8b       d8 88         8PP\"\"\"\"\"\"\"  `\"Yxba,    88     \n \
  88   \"8a,   ,a8\" 88         \"8b,   ,aa aa    ]8I   88,    \n \
  88    `\"YbbdP\"'  88          `\"Ybbd8\"' `\"YbbdP\"'   \"Y888  " nl2;


	for (int i = n; i; --i)
	{
		print_trees();
		std::cout << s;
	}
	print_trees();
}*/
