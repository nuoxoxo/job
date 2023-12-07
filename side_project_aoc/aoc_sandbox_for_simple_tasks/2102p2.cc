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
			D += n * aim;
		}
		if (op == "up")
		{
			aim -= n;
		}
		if (op == "down")
		{
			aim += n;
		}
	}
	std::cout << "result: " << H * D << std::endl;
}
