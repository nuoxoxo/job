#pragma once
#ifndef __RPN_HPP__
# define __RPN_HPP__

# include "iostream"
# include "sstream"
# include "stack"
# include "cassert"

# define Error "Error"
# define nl "\n"
# define nl2 "\n\n"
# define nlreset " \n" RESET
# define nl2reset " \n\n" RESET
# define LOWKEY "\033[0;2m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define MAG "\033[0;35m"
# define RED "\033[0;31m"
# define RESET "\033[0;0m"
# define ITAL "\033[3m"

# define TICK	GREEN " ✓" RESET
# define CROSS	RED " ✘" RESET

// helpers

void	calculator(std::string, std::string);
void	calculator(std::string, int);
void	calculator(std::string);
void	debugger();
bool	check_expression(std::string &);
void	header(const char *);
// void	header(std::string const);

std::string	RPN(std::string);

//to_string not include in c++98
template<typename T>
	std::string to_string(const T &);

#endif


