#include "Cpp06.hpp"
#include "iostream"
#include "sstream"
#include "iomanip"
#include "cmath" // isnan

#define C "char: "
#define I "int: "
#define F "float: "
#define D "double: "
#define IM "impossible "
#define ND "Non displayable "

// 	Quote:
//	"Integers are inherently finite. " - someone on stackoverflow


//	proto

struct	_Scalar_
{
	char	c;
	int	i;
	float	f;
	double	d;
};

static void	_usage_();
static void	Printer(_Scalar_ *sc);
static void	Brain(const char *);

static bool	strIsChar(const std::string &);
static bool	strIsDigit(const std::string &);
static bool	strIsFloat(const std::string &);
static bool	strIsDouble(const std::string &);

static bool	isMacroFloat(const std::string & s);
static bool	isMacroDouble(const std::string & s);

static void	castInt(const std::string &, _Scalar_ *);
static void	castChar(const std::string &, _Scalar_ *);
static void	castFloat(const std::string &, _Scalar_ *);
static void	castDouble(const std::string &, _Scalar_ *);


//	drive

int	main(int c, char **v)
{
	if (c ^ 2)
		return (_usage_(), 1);

	// std::cout << strIsDigit(std::string(v[1])) << std::endl;
	// std::cout << strIsChar(std::string(v[1])) << std::endl;

	Brain(v[1]);

	(void) c, (void) v;
}


//	define

static void	_usage_()
{
	std::cout << nl YELL "Usage: ./convert _literal_ " RESET nl2;
}


//	convertor . brain

static void	Brain(const char * str)
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
		{
			// std::cout << "current level: " << i << std::endl;
			// // to delete
			
			return (mode_convertor[i](s, & SC), Printer(& SC));
		}
	}
	std::cout << YELL "convertion failed. " nl2 RESET ;
}


//	Type checking:
//		char 
//		digit (int) 
//		float 
//		double

static bool	strIsChar(const std::string & s)
{
	return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

static bool	strIsDigit(const std::string & s)
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

static bool	strIsFloat(const std::string & str)
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

static bool	strIsDouble(const std::string & str)
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
	float			tmp;

	ss >> tmp;
	if (!ss.eof() || ss.fail())
		return false;
	return true;

	/*
	std::stringstream	ss(s);
	double			tmp;

	ss >> tmp;
	if (!ss.eof() || ss.fail())
		return false;
	return true;
	*/
}


//	is macro group

static bool	isMacroFloat(const std::string & s)
{
	return (s == "inff" || s == "-inff" || s == "+inff" || s == "nanf");
}

static bool	isMacroDouble(const std::string & s)
{
	return (s == "inf" || s == "-inf" || s == "+inf" || s == "nan");
}


//	Type casting:
//		char 
//		digit (int) 
//		float 
//		double

static void	castChar(const std::string & s, _Scalar_ *sc)
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

static void	castInt(const std::string & s, _Scalar_ *sc)
{
	if (s.empty() || !sc)
		return ;

	/*std::cout << "route int: " << __FUNCTION__ << std::endl;
	*/

	// step 1. convert principle type
	sc->i = std::stoi(s);

	// step 2. convert the rest based on principle type
	sc->c = static_cast<char> (sc->i);
	sc->f = static_cast<float> (sc->i);
	sc->d = static_cast<double> (sc->i);

	/*
	std::cout << std::fixed << std::setprecision(10);
	std::cout << RED << "i: " << sc->i << nl RESET;
	std::cout << RED << "f: " << sc->f << nl RESET;
	std::cout << RED << "d: " << sc->d << nl RESET;
	*/
}

static void	castFloat(const std::string & s, _Scalar_ *sc)
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

static void	castDouble(const std::string & s, _Scalar_ *sc)
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

static void	Printer(_Scalar_ *sc)
{
	// char
	if (sc->i < -1 * (1 << 7) || sc->i > (1 << 7) - 1)
		std::cout << YELL C IM nl RESET;
	else if (std::isprint(sc->c))
		std::cout << C "'" << sc->c << "'" nl;
	else
		std::cout << CYAN ND nl RESET;

	// int
	/*std::cout << GREEN "int route (i): " << sc->i << nl;
	std::cout << GREEN "int route (d): " << sc->d << nl;
	std::cout << GREEN "int route (f): " << sc->f << nl RESET;
	*/

	/*
	if (isnan(sc->f))
		std::cout << "1" nl;
	
	if (sc->d >= 2147483648.0)
		std::cout << "2" nl;

	// if (sc->d <= -2147483648.0) // here
	if (sc->d <= -2147483648.0)
		std::cout << "3" nl;
	*/
	
	//if (isnan(sc->d) || sc->d > 2147483647.0 || sc->d < -2147483648.0)
	//// above: mini

	if (  isnan(sc->f) || sc->d > 2147483647.0 || sc->d < -2147483648.0)
		std::cout << YELL I IM nl RESET;
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
