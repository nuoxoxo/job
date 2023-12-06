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

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "iostream"
# include "cstdlib"
# include "string" 
# include "Utils.hpp"

class Contact
{
	std::string m_first_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string m_phone;
	std::string m_secret;

	public:
		Contact();
		virtual ~Contact();

	public:
		void set_first_name(std::string first)	{ this->m_first_name = first;}
		void set_last_name(std::string last)	{ this->m_last_name = last; }
		void set_nickname(std::string nick)		{ this->m_nickname = nick; }
		void set_phone(std::string gameboy)		{ this->m_phone = gameboy; }
		void set_secret(std::string stuff)		{ this->m_secret = stuff; }
		std::string get_first_name() const		{ return (this->m_first_name); }
		std::string get_last_name() const		{ return (this->m_last_name); }
		std::string get_nickname() const		{ return (this->m_nickname); }
		std::string get_phone() const			{ return (this->m_phone); }
		std::string get_secret() const			{ return (this->m_secret); }

		int	add(void);
};

#endif
