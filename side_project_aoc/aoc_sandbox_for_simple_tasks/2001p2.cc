#include "iostream"
#include "vector"

int	main()
{
	std::vector<int> v;
	int n, res = 0;
	while (std::cin >> n)
		v.push_back(n);
	for (int a: v)
	{
		for (int b: v)
		{
			for (int c: v)
			{
				if (a ^ c && b ^ c && a ^ c && a+b+c == 2020)
					res = a*b*c;
			}
		}
	}
	std::cout << res << std::endl;
}
