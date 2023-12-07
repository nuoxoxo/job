#include "iostream"
#include "set"

int	main()
{
	std::set<int> s;
	int n;
	while (std::cin >> n)
	{
		if (s.find(2020 - n) != s.end())
			 break ;
		s.insert(n);
	}
	std::cout << n << std::endl;
	std::cout << (2020 - n) * n << std::endl;
}
