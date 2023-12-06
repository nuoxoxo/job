/* ************************************************************************** */
/*                                                                            */
/*                                                       .!.      .:+!^!+:.   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    :!. .!:         !:.     */
/*   By: nuo <marvin@42.fr>                         +.+  :+:       :.:        */
/*                                                .:+!+:._.:.    +.+          */
/*   Created: ____/__/__ __:__:__ by nuo               :..    ...             */
/*   Updated: 2023/01/06 08:28:26 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iostream"
# include "fstream"
# include "string"
# include "cstdio"

bool	_check_params_(int, char **);
void	_usage_(const std::string);

int	main(int c, char *v[])
{
	std::string::size_type	it;
	std::ifstream		ifs;
	std::ofstream		ofs;
	std::string		from, to;
	std::string		res, s;

	int			L;

	// try access v1
	if (!_check_params_(c, v))
		return 1;

	std::string	file(v[1]);

	if (file == "")
		return (_usage_("filename cannot be empty. "), 1);
	if (ifs.is_open())
		ifs.close();
	ifs.open(file.c_str());
	if (ifs.fail())
		return (_usage_("file not found "), 1);

	// access v2 v3
	from = std::string(v[2]);
	to = std::string(v[3]);
	if (from == "" || to == "")
		return (_usage_("either infile or outfile is empty. "), 1);
	
	// stream edit
	L = from.length();
	// it = 0; // works with or w/o
	while (getline(ifs, s))
	{
		it = s.find(from);
		while (it != std::string::npos)
		{
			s.erase(it, L);
			s.insert(it, to);
			it += to.length(); // bug fixed :: to avoid the infinite loop......//FIXME
			it = s.find(from, it); // bug fixed :: when do ./replace text lol lollol //FIXME
		}
		s += "\n";
		it = 0; // bug fixed :: //FIXME
		res.append(s);
	}
	file += ".replace";
	ofs.open(file.c_str());
	if (ofs.fail())
		return (_usage_("file not found "), 1);
	ofs << res;
	ifs.close();
	ofs.close();
}

//	deprecatd

/*
bool	sub(std::string from, std::string to, std::ifstream is, std::ofstream os)
{
//	std::string::size_type	it;
	std::string		s;
	std::string		res;
	int			L;

	if (from == "" || to == "")
	{
		usage("either from or to is empty. ");
		return false;
	}
	L = from.Lgth();
	while (gets(is, s))
		std::cout << s;
	return true;
}
*/

bool	_check_params_(int c, char *v[])
{
	std::string		from;
	std::string		to;
	if (c ^ 4)
	{
		_usage_("");
		return false;
	}
	from = std::string(v[2]);
	to = std::string(v[3]);
	if (from == "" || to == "")
		return (_usage_("the argument cannot be empty. "), false);
	return true;
}

void	_usage_(const std::string msg)
{
	if (msg != "")
		std::cerr << msg << "\n\n";
	std::cerr << "Usage: ./replace file from to " << std::endl;
}
