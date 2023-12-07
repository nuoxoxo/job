#include "iostream"

int	main()
{
	int res = 0;
	int n = 0;
	while (++n < 1000)
	{
		if (n % 15 == 0)
		{
			res += n;
			continue ;
		}
		if (n % 3 == 0 || n % 5 == 0)
			res += n;
	}
	std::cout << res;
}
