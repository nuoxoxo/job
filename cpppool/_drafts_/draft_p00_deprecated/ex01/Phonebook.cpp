/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By:  nuxu <marvin@42.fr>                       ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuxu              ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nuxu             ...   ::::::::.fi       */
/*                                                                            */
/* ****************************************************************** nxu *** */

#include "Phonebook.hpp"

Phonebook::Phonebook() : m_size() { m_contact = new Contact[CONTACT_SIZE]; }
Phonebook::~Phonebook() {}

void	Phonebook::add()
{
	Contact		c;

	Phonebook::get_input(Contact::first, c);
	Phonebook::get_input(Contact::last, c);
	Phonebook::get_input(Contact::nick, c);
	Phonebook::get_input(Contact::phone, c);
	Phonebook::get_input(Contact::dark, c);
	m_contact[m_size % CONTACT_SIZE] = c;
	m_size += 1;
}

void	Phonebook::collect_garbage()
{
	delete[]	m_contact;
}

void	Phonebook::parse_input(std::string & s)
{
	if (s == "")
		return ;
	std::string charset = " \t\v\r\n";
    std::size_t start = s.find_first_not_of(charset);
    std::size_t end = s.find_last_not_of(charset);
	std::cout << '\'' << s << '\'' << s.length() << std::endl;
    s = start == end ? std::string(1, s[start]) : s.substr(start, end - start + 1);
	std::cout << '\'' << s << '\'' << s.length() << std::endl;
}

//	previous version

// {
	// while (++i < len)
	// {
	// 	if (s[i] != ' ')
	// 		break ;
	// }
	// s = s.substr(i);
	// i = len;
	// while (--i > -1)
	// {
	// 	if (s[i] != ' ')
	// 		break ;
	// }
	// if (i >= len - 1)
	// 	return ;
	// std::cout << '\'' << s << '\'' << s.length() << std::endl;
	// s.erase(s.begin() + i + 1, s.end());
	// std::cout << '\'' << s << '\'' << s.length() << std::endl;
// }


void	Phonebook::get_input(int i, Contact & c)
{
	std::string		input;
	
	while (input.empty())
	{
		std::cout << Contact::keys[i] << "\n➜➜ ";
		getline(std::cin, input);
		Phonebook::parse_input(input);
		if (input == "")
			continue ;
		if (std::cin.eof())
			exit (1);
	}
	c.vals[i] = input;
}

void	Phonebook::search()
{
	int	 i;

	if (Phonebook::is_empty())
	{
		std::cout << "The phonebook is empty. \n";
		return ;
	}

	Phonebook::print_all();
	std::cout << "Enter a number associated with your desire. \n";
	std::cout << "Press 0 to return\n ➜ ";
	std::cin >> i;
	std::cin.clear();
	if (i < 1)
	{
		std::cout << "Phonebook Index should be a positive integer. \n";
		std::cin.ignore(256, '\n');
		return ;
	}
	if (i)
	{
		i = (i - 1) % CONTACT_SIZE;
	}
	m_fmt.fmt_printer(m_contact[i]);
	std::cin.ignore(256, '\n');
}

/*
	Notes:
		"init list" is used to set the value of m_size, which is set for
		the first time.
*/

std::string	Phonebook::linter(const std::string & line) const
{
	if (line.length() < 11)
	{
		return (line);
	}
	return (line.substr(0, 9).append("."));
}

void	Phonebook::print_col(const Fmt & fmt, std::size_t i) const
{
	std::cout << std::setw(WIDTH) << i + 1 << '|';
	std::cout << std::setw(WIDTH) << std::right << fmt.get_firstname() << '|';
	std::cout << std::setw(WIDTH) << std::right << fmt.get_lastname() << '|';
	std::cout << std::setw(WIDTH) << std::right << fmt.get_nickname() << '|';
}

void	Phonebook::print_all() const
{
	std::string	first, last, nick;
	std::size_t	i;

	std::cout << std::setw(WIDTH + 2 + FMT_HEAD_SIZE) << FMT_HEAD;
	std::cout << std::setw(WIDTH + 5) << "\n\n";

	std::cout << std::setw(WIDTH) << "index" << '|';
	std::cout << std::setw(WIDTH) << "First Name" << '|';
	std::cout << std::setw(WIDTH) << "Last Name" << '|';
	std::cout << std::setw(WIDTH) << "Nick Name" << '|';
	
	std::cout << "\n-----------\n";
	i = -1;
	while (++i < CONTACT_SIZE)
	{
		first = Phonebook::linter(m_contact[i].vals[0]);
		last = Phonebook::linter(m_contact[i].vals[1]);
		nick = Phonebook::linter(m_contact[i].vals[2]);

		Fmt			fmt(first, last, nick);

		Phonebook::print_col(fmt, i);
		std::cout << "\n-----------\n";
	}
}

bool	Phonebook::is_empty() const
{
	return (Phonebook::m_size == 0);
}
