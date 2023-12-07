#include "iostream"

#include "vector"
#include "sstream"

int	main()
{
	int H = 0, D = 0, aim = 0;
	std::string op;
	int n;
	while (std::cin >> op >> n)
	{
		if (op == "forward")
		{
			H += n;
		}
		if (op == "up")
		{
			D -= n;

		}
		if (op == "down")
		{
			D += n;
		}
	}
	std::cout << H << ' ' << D << std::endl;
	std::cout << "result: " << H*D << std::endl;
}
