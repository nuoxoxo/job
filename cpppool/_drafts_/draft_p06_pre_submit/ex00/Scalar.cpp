#include "Scalar.hpp"

//	define

void	_usage_()
{
	std::cout << nl YELL "Usage: ./convert _literal_ " RESET nl2;
}


//	convertor . brain

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

	bool	(*mode_isLiteral[4]) (const std::string &) =
	{
		& strIsChar,
		& strIsDigit,
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
		if (mode_isLiteral[i](s))
			return (mode_convertor[i](s, & SC), Printer(& SC));
	}
	std::cout << RED "Conversion failed. " RESET nl;
}

//	Type checking:
//		char 
//		digit (int) 
//		float 
//		double

bool	strIsChar(const std::string & s)
{
	return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

bool	strIsDigit(const std::string & s)
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

	int		len = (int) str.length();

	if (str[len - 1] != 'f')
		return false;

	std::string::const_iterator	it;
	std::string			s;

	s = str.substr(0, len - 1);
	it = s.begin();
	while (it != s.end() && (*it == '.' || std::isdigit(*it)))
		++it;;
	if (it != s.end())
		return false;

	std::stringstream	ss(s);
	float			tmp;

	ss >> tmp;
	if (!ss.eof() || ss.fail())
		return false;
	return true;
}

bool	strIsDouble(const std::string & str)
{
	if (isMacroDouble(str))
		return true;

	std::string::const_iterator	it;
	std::string			s;
	int				len;

	len = (int) str.length();
	s = str;
	it = s.begin();
	while (it != s.end() && (*it == '.' || std::isdigit(*it)))
		++it;;
	if (it != s.end())
		return false;

	std::stringstream	ss(s);
	double			tmp;

	ss >> tmp;
	if (!ss.eof() || ss.fail())
		return false;
	return true;
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


//	Type casting:
//		char 
//		digit (int) 
//		float 
//		double

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
	sc->i = std::stoi(s);

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
	sc->f = static_cast<float>(std::stof(s));

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
	sc->d = std::stod(s);

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
		std::cout << RED C IM nl RESET;
	else if (std::isprint(sc->c))
		std::cout << C "'" << sc->c << "'" nl;
	else
		std::cout << RED ND nl RESET;

	// int
	if (  isnan(sc->f) || sc->d > 2147483647.0 || sc->d < -2147483648.0)
		std::cout << RED I IM nl RESET;
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


//	Global

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

