#include "iostream"
#include "string"

using	namespace std;

int	main(int c, char **v)
{
	if (c ^ 2) return 1;

	string	s = string(v[1]);
	string	ss = s.substr(0, s.length() - 1);
	cout << s << " - " << ss << endl;
}
