#include "_.hpp"

int	main()
{
	vector<string>	a;
	string		s;

	while (cin >> s)
	{
		a.push_back( s );
		print(s);
	}
	cout << "(" << a.size() << " lines)\n";
}
