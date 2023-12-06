#include "iostream"
#include "string"

#define debug_level \
"I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it! \n\n"
#define info_level \
"I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it! \n\n"
#define warning_level \
"I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month. \n\n"
#define error_level \
"This is unacceptable, I want to speak to the manager now. \n\n"

class	Karen
{
	private:
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
	public:
		Karen(void);
//		~Karen(void);
		void		complain(std::string);
		virtual		~Karen(void);
};

//	driue

int	main(void)
{
	Karen		he;

	he.complain("debug");
	he.complain("info");
	he.complain("warning");
	he.complain("error");
	he.complain("");
	he.complain("john conway");
	he.complain("terry davis");
	he.complain("bjarne stroustrup");
}

//	member funcs

Karen::Karen(void) {}

Karen::~Karen(void) {}

void	Karen::debug(void)
{
	std::cout << __FUNCTION__ << '\n' << debug_level;
}

void	Karen::info(void)
{
	std::cout << __FUNCTION__ << '\n' << info_level;
}

void	Karen::warning(void)
{
	std::cout << __FUNCTION__ << '\n' << warning_level;
}

void	Karen::error(void)
{
	std::cout << __FUNCTION__ << '\n' << error_level;
}

void	Karen::complain(std::string level)
{
	int		i;

	if (level == "")
		return ;

	std::string	levels[] =
	{
		"debug",
		"info",
		"warning",
		"error"
	};

	void	(Karen::*modes[]) (void) =
	{
		& Karen::debug,
		& Karen::info,
		& Karen::warning,
		& Karen::error
	};

	for (i = 0; i < 4; ++i)
		if (levels[i] == level)
			(this->*modes[i])();
}
