/* ************************************************************************** */
/*                                                                            */
/*                                                       .!.      .:+!^!+:.   */
/*   _                                                  .":      .:!    .:!   */
/*                                                    :!. .!:         !:.     */
/*   By: nuo <marvin@42.fr>                         +.+  :+:       :.:        */
/*                                                .:+!+:._.:.    +.+          */
/*   Created: ____/__/__ __:__:__ by nuo               :..    ...             */
/*   Updated: ____/__/__ __:__:__ by nuo              :._    .:.:_:.:.:.      */
/*                                                                            */
/* ************************************************************************** */

# include "iostream"
# include "fstream"
# include "string"

bool	check_params(int, char **);
void	usage(std::string);

int	main(int c, char *v[])
{
	std::string::size_type		it;
	std::ifstream			ifs;
	std::ofstream			ofs;
	std::string			s1, s2, file;
	std::string			line;
	std::string			text;
	int				len;

	if (!check_params(c, v))
		return 1;
	file = std::string(v[1]);
	if (file == "")
	{
		usage("filename cannot be empty. ");
		return 1;
	}
	if (ifs.is_open())
		ifs.close();
	ifs.open(file);
	if (ifs.fail())
	{
		usage("file not found ");
		return 1;
	}

	/* the replacement proper begins here */

	s1 = std::string(v[2]);
	s2 = std::string(v[3]);
	if (s1 == "" || s2 == "")
	{
		usage("either s1 or s2 is empty. ");
		return 1;
	}
	len = s1.length();
	while (getline(ifs, line))
	{
		it = line.find(s1);
		while (it != std::string::npos)
		{
			line.erase(it, len);
			line.insert(it, s2);
			it = line.find(s1);
		}
		line += "\n";
		text.append(line);
	}
	std::transform(file.begin(), file.end(), file.begin(), ::toupper);
	file += ".replace";
	ofs.open(file);
	ofs << text;
	ifs.close();
	ofs.close();
}

//

/*
bool	sub(std::string s1, std::string s2, std::ifstream is, std::ofstream os)
{
//	std::string::size_type	it;
	std::string		line;
	std::string		text;
	int			len;

	if (s1 == "" || s2 == "")
	{
		usage("either s1 or s2 is empty. ");
		return false;
	}
	len = s1.length();
	while (getline(is, line))
		std::cout << line;
	return true;
}
*/

/*
bool	setup_infile(std::ifstream ifs, std::string filename)
{
}
*/

bool	check_params(int c, char *v[])
{
	std::string		s1;
	std::string		s2;
	if (c ^ 4)
	{
		usage("");
		return false;
	}
	s1 = std::string(v[2]);
	s2 = std::string(v[3]);
	if (s1 == "" || s2 == "")
	{
		usage("the argument cannot be empty. ");
		return false;
	}
	return true;
}

void	usage(std::string msg)
{
	if (msg != "")
		std::cerr << msg << "\n\n";
	std::cerr << "Usage: ./replace file s1 s2 " << std::endl;
}
