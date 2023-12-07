#include "iostream"

int	main(void)
{
	std::string	dir;
	int		x;
	int		aim, hps, dep, hps2, dep2;

	hps = dep = 0;
	hps2 = dep2 = aim = 0;
	while (std::cin >> dir >> x)
	{
		if (dir[0] == 'f')
		{
			hps += x;
			hps2 += x;
			dep2 += aim * x;
		}
		else
		{
			if (dir[0] == 'u')
				x = -x;
			dep += x;
			aim += x;
		}
	}
	std::cout << "Star 1: " << hps * dep << std::endl;
	std::cout << "Star 2: " << hps2 * dep2 << std::endl;
}
