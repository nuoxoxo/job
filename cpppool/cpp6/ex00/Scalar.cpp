/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                             ~  ~  ~  ~  ~    ~                             */
/*                              ~    _ ~ _   o>                               */
/*                             ~  \ / \ / \ /  ~                              */
/*                              ~  ~      ~    ~                              */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                  Casting                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* *********************  ʕ • ᴥ•ʔ  mode: todo  (⊙. ⊙ )  ********************* */

#include "Scalar.hpp"

void	Brain(const char * str)
{
	std::string	s;
	_Scalar_	SC;
	int		i;

	/* void	(Harl::*modes[4]) (void) = {
		& Harl::debug,
		& Harl::info,
		& Harl::warning,
		& Harl::error
	}; */

	if (isMacroFloat(str) || isMacroDouble(str))
	{
		impossiblePrinter(str);
		return ;
	}

	bool	(*mode_isLiteral[4]) (const std::string &) =
	{
		& strIsChar,
		& strIsInt,
		& strIsFloat,
		& strIsDouble
	};

	void	(*mode_convertor[4]) (const std::string &, _Scalar_ *) =
	{
		& castChar,
		& castInt,
		& castFloat,
		& castDouble
	};

	s = std::string(str);
	i = -1;
	while (++i < 4)
	{
		if ( !mode_isLiteral[i](s))
			continue ;
		return (mode_convertor[i](s, & SC), Printer(& SC));
	}
	std::cout << YELL "Conversion failed. " RESET nl;
}

//	
//	Type checking
//	

bool	strIsChar(const std::string & s)
{
	return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

bool	strIsInt(const std::string & s)
{
	// checking string contains only digit
	if (s.empty())
		return false;

	std::string::const_iterator	it = s.begin();

	while (it != s.end() && std::isdigit(*it))
		++it;;
	if (it != s.end())
		return false;

	// checking conversion w/ ss
	std::stringstream	ss(s);
	int			tmp;

	ss >> tmp;
	if (!ss.eof() || ss.fail())
		return false;
	return true;
}

bool	strIsFloat(const std::string & str)
{
	if (isMacroFloat(str)) // (marco: see below)
		return true;
	if (str[(int) str.length() - 1] != 'f')
		return false;

	// std::string::const_iterator	it;
	std::string			s;
	int				len;

	len = (int) str.length();
	s = str.substr(0, len - 1);
	// it = s.begin();
	// while (it != s.end() && (*it == '.' || std::isdigit(*it)))
	// 	++it;;
	// if (it != s.end())
	// 	return false;

	std::stringstream	ss(s);
	float			tmp;

	ss >> std::noskipws >> tmp;

	return (ss.eof() && !ss.fail());
}

bool	strIsDouble(const std::string & str)
{
	if (isMacroDouble(str))
		return true;

	// std::string::const_iterator	it;
	std::string			s;
	int				len;

	len = (int) str.length();
	s = str;
	// it = s.begin();
	// while (it != s.end() && (*it == '.' || std::isdigit(*it)))
	// 	++it;;
	// if (it != s.end())
	// 	return false;

	std::stringstream	ss(s);
	double			tmp;

	ss >> std::noskipws >> tmp;

	return (ss.eof() && !ss.fail());
}


//	is macro group

bool	isMacroFloat(const std::string & s)
{
	return (s == "inff" || s == "-inff" || s == "+inff" || s == "nanf");
}

bool	isMacroDouble(const std::string & s)
{
	return (s == "inf" || s == "-inf" || s == "+inf" || s == "nan");
}


//	
//	Type casting
//

void	castChar(const std::string & s, _Scalar_ *sc)
{
	if (s.empty() || !sc)
		return ;
	
	// step 1. convert principle type
	sc->c = s[1];

	// step 2. convert the rest based on principle type
	sc->i = static_cast<int> (sc->c);
	sc->f = static_cast<float> (sc->c);
	sc->d = static_cast<double> (sc->c);
}

void	castInt(const std::string & s, _Scalar_ *sc)
{
	if (s.empty() || !sc)
		return ;

	// step 1. convert principle type
	// sc->i = std::stoi(s); // c++11
	std::stringstream(s) >> sc->i;

	// step 2. convert the rest based on principle type
	sc->c = static_cast<char> (sc->i);
	sc->f = static_cast<float> (sc->i);
	sc->d = static_cast<double> (sc->i);
}

void	castFloat(const std::string & s, _Scalar_ *sc)
{
	if (s.empty() || !sc)
		return ;

	// step 1. convert principle type
	// c->f = static_cast<float>(std::stof(s)); // c++11
	float	res;
	std::stringstream(s) >> res;
	sc->f = static_cast<float>(res);
	
	// step 2. convert the rest based on principle type
	sc->c = static_cast<char>(sc->f);
	sc->i = static_cast<int>(sc->f);
	sc->d = static_cast<double>(sc->f);
}

void	castDouble(const std::string & s, _Scalar_ *sc)
{
	if (s.empty() || !sc)
		return ;

	// step 1. convert principle type
	// sc->d = std::stod(s); // c++11
	std::stringstream(s) >> sc->d;


	// step 2. convert the rest based on principle type
	sc->c = static_cast<char>(sc->d);
	sc->i = static_cast<int>(sc->d);
	sc->f = static_cast<float>(sc->d);

}

//	Printer

void	Printer(_Scalar_ *sc)
{
	// char
	if (sc->i < -1 * (1 << 7) || sc->i > (1 << 7) - 1)
		std::cout << C YELL IM nl RESET;
	else if (std::isprint(sc->c))
		std::cout << C "'" << sc->c << "'" nl;
	else
		std::cout << C YELL ND nl RESET;

	// int
	if (std::isnan(sc->f) || sc->d > 2147483647.0 || sc->d < -2147483648.0)
		std::cout << I YELL IM nl RESET;
	else
		std::cout << I << sc->i << nl;

	// float
	std::cout
	<< F
	<< std::setiosflags(std::ios::fixed)
	<< std::setprecision(1)
	<< sc->f << "f" nl
	<< std::resetiosflags(std::ios::fixed);

	// double
	std::cout
	<< D
	<< std::setiosflags(std::ios::fixed)
	<< std::setprecision(1)
	<< sc->d << nl
	<< std::resetiosflags(std::ios::fixed);
}

void	impossiblePrinter(const std::string & _)
{
	std::string	ds, fs;

	std::cout << C YELL IM nl RESET;
	std::cout << I YELL IM nl RESET;

	ds = _;
	fs = _;
	if (_[0] == '+')
	{
		ds = _.substr(1, _.length() - 1);
		fs = ds;
	}
	if (isMacroDouble(_))
	{
		fs += 'f';
	}
	if (isMacroFloat(_))
		ds = ds.substr(0, ds.length() - 1);

	std::cout << F << fs << nl;
	std::cout << D << ds << nl;

	
	// std::cout << D
	// << ((isMacroFloat(_)) ? ((_[0] == '+') ? _.substr(1, _.length() - 1) : _.substr(0, _.length() - 1) + nl) : _ + nl);
}


//	misc.

void	_usage_()
{
	std::cout << nl YELL "Usage: ./convert _literal_ " RESET nl2;
}

void	print_canon(const std::string funcName, const std::string canonName)
{
	std::cout << LOWKEY << funcName << ' ' << canonName << called RESET;
}

void	print_ending(int i)
{
	std::cout
	<< LOWKEY nl2 
	<< ":::::::::::: end test " << i << " ::::::::::::" nl2 RESET;
}

void	print_ending(void)
{
	std::cout
	<< LOWKEY nl2 
	<< ":::::::::::: end test ::::::::::::" nl2 RESET;
}

void	print_ending(std::string & s)
{
	std::cout
	<< LOWKEY nl2
	<< ":::::::::::: end test (" << s << ") ::::::::::::" nl2 RESET;
}

void	print_ending(int i, const std::string s)
{
	std::cout
	<< LOWKEY nl 
	<< ":::::::::::: end test "
	<< i << " (" << s << ") ::::::::::::" nl2 RESET;
}

