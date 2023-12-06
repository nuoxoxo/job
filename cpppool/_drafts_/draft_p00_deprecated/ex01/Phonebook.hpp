/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By:  nuxu <marvin@42.fr>                       ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuxu              ...    :::             */
/*   Updated: 2022/12/02 10:06:34 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ****************************************************************** nxu *** */

#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

# include "iostream"
# include "iomanip" // for std::setw
# include "cstdlib" // for exit()

# include "Contact.hpp"
# include "Fmt.hpp"

class	Phonebook
{
	private:
		std::size_t		m_size;
		Contact			*m_contact;
		Fmt				m_fmt;
	private:
		void			print_all(void) const;
		void			print_col(const Fmt & m_fmt, std::size_t) const;
		std::string		linter(const std::string &) const;

	public:
		Phonebook();
		virtual	~Phonebook();

		void		add(void);
		void		search(void);
		bool		is_empty(void) const;
		void		get_input(int, Contact & contact);		
		void		collect_garbage(void);
		void		parse_input(std::string& s);
};

# define CONTACT_SIZE 8
# define WIDTH 10

# define FMT_HEAD_SIZE 18
# define FMT_HEAD "--- Phonebook ---"

# define NL2 "\n\n"
# define SKIP_PROMPT " \n➜ \n"

# define NOCMD "Service unavailable. Please re-enter your command \n"
# define USAGE "➜ [Usage]: Enter your command [Add, Search, Exit]"
# define ONAIR "➜ Your awesome phonebook is online. \n"
# define DELIM "----------8<----[ cut here ]---------------- "

#endif
