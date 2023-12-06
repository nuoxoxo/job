#include "iostream"

using	namespace std;

int	main()
{
	float	f = 42.42;

	int	a = f;
	int	b = static_cast<int>(f);
	int	ff = static_cast<float>(f);
	int	aa = static_cast<float>(a);

	cout << a << endl;
	cout << b << endl;
	cout << (float)ff << endl;
	cout << (float)aa << endl;
}
