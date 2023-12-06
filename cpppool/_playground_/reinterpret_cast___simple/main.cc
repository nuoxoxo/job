#include "iostream"
#include "cstdlib"

using	namespace std;

// data_type	*var_name = reinterpret_cast <data_type *>(pointer_variable);

int	main()
{
	int	*v = new int(65);
	char	*c = reinterpret_cast<char *>(v);

	cout << *v << endl;
	cout << *c << endl;
	cout << v << endl;
	cout << c << endl;
}
