#include "iostream"

using	namespace std;

int	main()
{
	string s;
	cin >> s;
	cout << s << endl;
	int i, len = s.length();
	string res, res2;
	i = 0;
	while (i < len - 1)
	{
		if (((s[i] <= 'Z' && s[i] >= 'A') || s[i] == '-') && s[i] == s[i + 1])
		{
			res += s[i];
			i += 2;
			continue ;
		}
		if (s[i] <= '9' && s[i] >= '0' && s[i] == s[i + 1])
		{
			res2 += s[i];
			i += 2;
			continue ;
		}
		++i;
	}
	cout << "p1: " << res << endl;
	cout << "p2: " << res2 << endl;
}

