#include "iostream"
#include "string"

#define debug_level \
"[ DEBUG ]\nI love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n\n"
#define info_level \
"[ INFO ]\nI cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n\n"
#define warning_level \
"[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming here for years and you just started working here last month.\n\n"
#define error_level \
"[ ERROR ]\nThis is unacceptable, I want to speak to the manager now.\n\n"

#define insignificant "[ Probably complaining about insignificant problems ]\n\n"

//	class

class	Karen {
	private:
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
	public:
		Karen(void);
		//~Karen(void);
		virtual		~Karen(void);
		void		complain(std::string);
};

//	prototyping

void		usage(void);

//	drive

int	main(int c, char *v[])
{
	Karen		Kafka;

	if (c ^ 2)
		return (usage(), 0);
	//std::cout << std::endl; // against the subj
	Kafka.complain(std::string(v[1]));
}

Karen::Karen(void) {}
Karen::~Karen(void) {}

void	Karen::debug(void)	{ std::cout << debug_level; }
void	Karen::info(void)	{ std::cout << info_level; }
void	Karen::warning(void)	{ std::cout << warning_level; }
void	Karen::error(void)	{ std::cout << error_level; }

void	Karen::complain(std::string level)
{
	bool		found;
	int		i;

	if (level == "")
		return ;

	std::string	levels[] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	void	(Karen::*modes[]) (void) =
	{
		& Karen::debug,
		& Karen::info,
		& Karen::warning,
		& Karen::error
	};

	found = false;
	i = -1;
	while (++i < 4)
	{
		if (found)
		{
			(this->*modes[i])();
		}
		else if (!found && levels[i] == level)
		{
			(this->*modes[i])();
			found = true;
		}
		
	}
	if (found)
		return ;
	std::cout << insignificant << std::endl;
}

void	usage()
{
	std::cout << "Usage: ./karenFilter [ stuff_like_maybe_a_complain_level ] ";
	std::cout << std::endl;
}
