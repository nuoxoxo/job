#include "vector"
#include "iostream"
#include "sstream"
#include "string"

int	main()
{
	std::vector<long long>	res;
	long long		n;
	int			i;

	std::cin >> n;
	while (n != 1)
	{
		res.push_back(n);
		if (n % 2)
			n = 3 * n + 1;
		else
			n /= 2;
	}
	if ((int) res.size() == 0 || res.back() != 1)
		res.push_back(1);
	i = 0;
	std::cout << res[i];
	while (++i < (int) res.size())
	{
		std::cout << ' ' << res[i];
	}
	return (0);
}
