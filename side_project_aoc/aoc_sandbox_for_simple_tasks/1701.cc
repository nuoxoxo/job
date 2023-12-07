#include "iostream"

int	main()
{
	std::string s;
	std::cin >> s;
	int res = 0, i = -1;
	while (++i < s.length())
	{
		int next = i + 1;
		if (i + 1 == s.length())
			next = 0;
		if (s[i] != s[next])
			continue ;
		res += s[i] - '0';
	}
	int res2 = 0, mid = s.length() / 2;
	i = -1;
	while (++i < s.length() / 2)
	{
		if (s[i] == s[i + mid])
			res2 += 2 * (s[i] - '0');
	}
	std::cout << res << '\n';
	std::cout << res2 << '\n';
}
