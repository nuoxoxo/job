#include "iostream"
#include "cstdlib"
#define nl "\n"
#define nl2 "\n\n"

using	namespace std;

// data_type	*var_name = reinterpret_cast <data_type *>(pointer_variable);

class	Convert
{
public:
	Convert();
	~Convert();
	int	i;
	int	j;
	float	f;
	char	c;
	bool	b;
	void	printer() const;
};

Convert::Convert() : i(), j(), f(), c(), b() {}
Convert::~Convert() {}

void	Convert::printer() const
{
	cout << i << nl;
	cout << j << nl;
	cout << f << nl;
	cout << c << nl;
	cout << boolalpha << b << nl2;
}

int	main()
{
	// Convert	*conv = new Convert();

	Convert	conv;

	/*
	conv->i = 42;
	conv->j = 1024;
	conv->f = 3.1415926f;
	conv->c = 'c';
	conv->b = true;
	conv->printer();
	*/

	conv.i = 42;
	conv.j = 1024;
	conv.f = 3.1415926f;
	conv.c = 'c';
	conv.b = true;
	conv.printer();

	cout << "size of conv (before cast) " << sizeof(conv) << nl;
	int	*ptr = reinterpret_cast<int *>(& conv);
	cout << "size of conv (after cast) " << sizeof(conv) << nl;
	
	cout << "*ptr - " << *ptr << nl;
	++ptr;
	cout << "*ptr - " << *ptr << nl2;

	// delete conv;
}
