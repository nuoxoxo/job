/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By:  nuxu <marvin@42.fr>                       ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuxu              ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nuxu             ...   ::::::::.fi       */
/*                                                                            */
/* ****************************************************************** nxu *** */

#include "Fmt.hpp"

Fmt::Fmt() {}

Fmt::Fmt	(	const std::string& first, 
				const std::string& last, 
				const std::string& nick
			) :	m_firstname(first), m_lastname(last), m_nickname(nick) { }

Fmt::~Fmt() {}

const	std::string & Fmt::get_firstname() const
{
	return (m_firstname);
}

const	std::string & Fmt::get_lastname() const
{
	return (m_lastname);
}

const	std::string & Fmt::get_nickname() const
{
	return (m_nickname);
}

void	Fmt::fmt_printer(const Contact & c) const
{
	std::cout << "First name: "		<< c.vals[0] << "\n";
	std::cout << "Last name: "		<< c.vals[1] << "\n";
	std::cout << "Nickname: "		<< c.vals[2] << "\n";
	std::cout << "Phone number: "	<< c.vals[3] << "\n";
	std::cout << "Dark secret: "	<< c.vals[4] << "\n";
}