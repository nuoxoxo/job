#include "iostream"
#include "vector"

int	main()
{
	std::vector<int> a{1, 2};
	int n;
	int res = 2;
	while (1)
	{
		int S = a.size();
		n = a[S - 2] + a[S - 1];
		if (n > 4000000)
			break ;
		if ((n & 1) == 0)
			res += n;
		a.push_back(n);
	}
	std::cout << res;
}
