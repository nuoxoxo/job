#include "iostream"
#include "map"
#include "vector"

int	main()
{
	int res = 0, n;
	int res2 = 0;
	std::map<int, int> M;
	std::vector<int> A;
	while (std::cin >> n)
	{
		res += n;
		A.push_back(n);
	}
	std::cout << res << std::endl;
	int i = 0, count = 0;
	res = 0;
	M[0] = 1;
	while (1)
	{
		res += A[i];
		++M[res];
		if (M[res] == 2)
			break ;
		i = i == A.size() - 1 ? 0 : i + 1;
		++count;
	}
	std::cout << res << " at " << count << std::endl;
}
