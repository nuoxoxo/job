#include "iostream"
#include "cstdlib"
#include "vector"

int	main()
{
	std::string s;
	int res = 0;
	int tmp = 0;
	std::vector<int> a;
	while (!std::cin.eof() && getline(std::cin, s))
	{
		if (s == "" || std::cin.eof())
		{
			res = std::max(res, tmp);
			a.push_back(tmp);
			tmp = 0;
			continue ;
		}
		tmp += stoi(s);
	}
	std::sort(a.begin(), a.end());
	int len = a.size();
	int res2 = a[len - 1] + a[len - 2] + a[len - 3];
	std::cout << res << '\n';
	std::cout << res2 << '\n';
}
