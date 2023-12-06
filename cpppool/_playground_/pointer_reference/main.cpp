#include "iostream"

using	namespace std;

int	main()
{
	int		i = 47 * 59 * 71;

	int		&ref = i;
	int		*ptr = &i;

	cout << "i: " << i << endl;
	cout << "&ref = i; \tref :\t" << ref << endl;
	//cout << "&ref = i; *ref" << *ref << endl;
	cout << "&ref = i; \t&ref :\t" << &ref << endl;
	cout << "*ptr = & i; \tptr :\t" << ptr << endl;
	cout << "*ptr = & i; \t*ptr :\t" << *ptr << endl;
	cout << "*ptr = & i; \t&ptr :\t" << &ptr << endl;
}
