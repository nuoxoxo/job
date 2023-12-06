#include "Cpp05.hpp"

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
