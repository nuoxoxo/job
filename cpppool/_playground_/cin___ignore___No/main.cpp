#include "iostream"
#include "string"

int	main()
{
	int			x;
	std::string		s;

	//	Prompt user for input
	std::cout << "enter an int & a string: ";

	//	Get input
	std::cin >> x;
	std::getline(std::cin, s);

	//	Show input
	std::cout << "your integer:\t" << x << '\n';
	std::cout << "your string:\t" << s << '\n';

	//	Explanation
	std::cout << "\n(*) it works strangely without cin.ignore \n";
}
