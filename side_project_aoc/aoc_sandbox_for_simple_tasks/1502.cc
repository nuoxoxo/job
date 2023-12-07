#include "iostream"
#include "cstdio"

using	namespace std;

int	m3(int a, int b, int c, int);

int	main()
{
	string s;
	int a, b, c;
	int res = 0;
	int res2 = 0;
	while (!cin.eof() && cin >> s)
	{
		sscanf(s.c_str(), "%dx%dx%d", & a, & b, & c);
		res += 2*a*b + 2*b*c + 2*a*c + m3(a*b, b*c, a*c,0);
		int wp = a*b*c;
		int bow = (a + b + c - m3(a, b, c,1)) * 2;
		res2 += wp + bow;
	}
	cout << res << '\n';
	cout << res2 << '\n';
	assert (res == 1586300);
	assert (res2 == 3737498);

}

int	m3(int a, int b, int c, int mode)
{
	int r;
	if (mode)
	{
		r = a > b ? a : b;
		r = r > c ? r : c;
	}
	else
	{
		r = a < b ? a : b;
		r = r < c ? r : c;
	}
	return r;
}
