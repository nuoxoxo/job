#include "iostream"

int	main()
{
	int res = 0, n;
	int res2 = 0;
	while (std::cin >> n)
	{
		res += n / 3 - 2;
		int temp = n / 3 - 2;
		while (temp > 0)
		{
			res2 += temp;
			temp = temp / 3 - 2;
		}
	}
	std::cout << res << std::endl;
	std::cout << res2 << std::endl;
}
