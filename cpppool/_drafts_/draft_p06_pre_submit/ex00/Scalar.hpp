#ifndef SCALAR_HPP
# define SCALAR_HPP

# include "iostream"
# include "string"
# include "sstream"
# include "iomanip"
# include "cmath" // isnan

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

void	_usage_();

void	Printer(_Scalar_ *sc);
void	Brain(const char *);

bool	strIsChar(const std::string &);
bool	strIsDigit(const std::string &);
bool	strIsFloat(const std::string &);
bool	strIsDouble(const std::string &);

bool	isMacroFloat(const std::string & s);
bool	isMacroDouble(const std::string & s);

void	castInt(const std::string &, _Scalar_ *);
void	castChar(const std::string &, _Scalar_ *);
void	castFloat(const std::string &, _Scalar_ *);
void	castDouble(const std::string &, _Scalar_ *);


void	print_canon(const std::string, const std::string);
void	print_ending(int);
void	print_ending(void);
void	print_ending(std::string &);
void	print_ending(int, const std::string);


//	colors

# define ITAL	"\033[3m"
# define LOWKEY	"\033[0;2m"
# define WHITE	"\033[1;37m"
# define CYAN	"\033[0;36m"
# define YELL	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define RED	"\033[0;31m"
# define MAG	"\033[0;35m"

# define RESET	"\033[0;0m"

# define TICK	GREEN" ✓"RESET
# define CROSS	RED" ✘"RESET


//	formatting

# define called " called\n"
# define inside "\ninside "
# define nl2 " \n\n"
# define nl " \n"

# define C "char: "
# define I "int: "
# define F "float: "
# define D "double: "
# define IM "impossible "
# define ND "Non displayable "


#endif
