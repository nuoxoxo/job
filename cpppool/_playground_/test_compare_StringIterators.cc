#include "iostream"
#include "string"

#define nl "\n"

using	namespace std;

int	main(int c, char **v)
{
	if (c ^ 2)
		return 1;

	string	line = string(v[1]);

	string	p = "president";
	string	s = "shrubbery";
	
	int	ip = line.find(p);
	int	is = line.find(s);
	
	cout << ip << nl;
	cout << is << nl;
}
