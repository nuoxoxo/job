#include "iostream"
#include "cstdio"

bool	f(int, int, char, std::string);
bool	ff(int, int, char, std::string);

int	main()
{
	int res = 0, lo, hi;
	int res2 = 0;
	char c;
	std::string L, M, R;
	while (std::cin >> L >> M >> R)
	{
		sscanf(L.c_str(), "%d-%d", & lo, & hi);
		c = M[0];
		// std::cout << lo << ' ' << hi << ' ' << c << ' ' << R << std::endl;
		if (f(lo, hi, c, R))
			++res;
		if (ff(lo-1, hi-1, c, R))
			++res2;
	}
	std::cout << res << std::endl;
	std::cout << res2 << std::endl;
}

bool	ff(int l, int r, char c, std::string s)
{
	return ((c == s[l] || c == s[r]) && s[l] != s[r]);
}

bool	f(int lo, int hi, char c, std::string s)
{
	int count = 0, i = -1;
	while (++i < s.length())
	{
		if (s[i] != c) continue ;
		++count;
	}
	if (count >= lo && count <= hi)
		return true;
	return false;
}
