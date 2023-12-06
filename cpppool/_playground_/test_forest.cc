#include "iostream"
#define nl2 " \n\n"
#define nl " \n"
# define TREE_UP	" ^  ^  ^   ^   ^  ^   ^  ^  ^   ^  ^   ^  ^  ^   ^   ^   ^  ^ \n"
# define TREE_DOWN "/|\\/|\\/|\\ /|\\ /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ /|\\/|\\/|\\ /|\\ /|\\ /|\\/|\\ \n"
using	namespace std;

void	print_tree(void)
{
	std::cout << TREE_UP TREE_DOWN TREE_DOWN TREE_DOWN << std::endl;
}

void	print_forest(void)
{
	string	s = "\n \
   ad88                                                     \n \
  d8\"                                                ,d     \n \
  88                                                 88     \n \
MM88MMM ,adPPYba,  8b,dPPYba,  ,adPPYba, ,adPPYba, MM88MMM  \n \
  88   a8\"     \"8a 88P'   \"Y8 a8P_____88 I8[    \"\"   88     \n \
  88   8b       d8 88         8PP\"\"\"\"\"\"\"  `\"Yxba,    88     \n \
  88   \"8a,   ,a8\" 88         \"8b,   ,aa aa    ]8I   88,    \n \
  88    `\"YbbdP\"'  88          `\"Ybbd8\"' `\"YbbdP\"'   \"Y888  " nl2;

	std::cout << s;

}

int	main()
{
	print_forest();
}
