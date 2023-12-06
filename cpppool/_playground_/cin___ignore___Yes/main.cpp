#include "iostream"
#include "string"
#include "limits"

int	main()
{
	int			x;
	std::string		s;

	//	Prompt user for input

	std::cout << "enter an int & a string: ";

	//	Get input

	std::cin >> x;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, s);

	//	Show input

	std::cout << "your integer:\t" << x << '\n';
	std::cout << "your string:\t" << s << '\n';

	//	Explanation
	std::cout << "\n(*) now with cin.ignore, it works beautifully \n";
}
