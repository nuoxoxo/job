#include "iostream"
#include "sstream"

using	namespace std;

int	main(int c, char **v)
{
	if (c ^ 2) return 1;
	string	s = string(v[1]);
	int 	a;
	stringstream	ss(s);
	a << ss;
//	ss >> a;

	cout << a << endl;
}
