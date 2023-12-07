#include "iostream"
#include "vector"

int	main()
{
	std::vector<int> A;
	int res = 0, i;
	while (std::cin >> i) A.push_back(i);
	i = 0;
	while (++i < A.size())
	{
		if (A[i] - A[i - 1] > 0)
			++res;
	}
	int res2 = 0;
	i = 2;
	while (++i < A.size())
	{
		if (A[i] > A[i - 3])
			++res2;
	}
	std::cout << res << std::endl;
	std::cout << res2 << std::endl;
}
