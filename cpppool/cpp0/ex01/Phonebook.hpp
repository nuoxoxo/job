/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By:  nuxu <marvin@42.fr>                       ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuxu              ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nuxu             ...   ::::::::.fi       */
/*                                                                            */
/* ****************************************************************** nxu *** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "iostream"
# include "string"
# include "iomanip" // for std::setw
# include "cstdlib" // for exit()
# include "Contact.hpp"
# include "Utils.hpp"

# define PHONEBOOK_THICKNESS 8
# define WIDTH 10

# define FMT_HEAD_SIZE 18
# define FMT_HEAD "--- Phonebook ---"

# define NL2 "\n\n"
# define SKIP_PROMPT " \n➜ \n"

# define NOCMD "Service unavailable. Please re-enter your command \n"
# define USAGE "➜ [Usage]: Enter your command [Add, Search, Exit]"
# define ONAIR "➜ Your awesome Phonebook is online. \n"
# define DELIM "----------8<----[ cut here ]---------------- \n"
# define HEAD "|     index|first name| last name|  nickname| \n"
# define FRAME "+-------------------------------------------+\n"

class Phonebook
{
	private:
		Contact			m_contacts[PHONEBOOK_THICKNESS];
		std::size_t		m_cursor;
	
	public:
		Phonebook();
		virtual ~Phonebook();

		void		append(Contact this_guy);
		void		print_all(void);
		void		print_col(int index);
		bool		is_empty() const;
		int			empty(int index);
		int			search(Phonebook);
		std::string	linter(std::string);
		// void		collect_garbage(void);
};



#endif
