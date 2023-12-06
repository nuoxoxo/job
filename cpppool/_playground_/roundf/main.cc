#include "iostream"
#include "cmath"

#define nl '\n'
#define nl2 "\n\n"

using	namespace std;

int	main()
{
	cout << roundf((float)42) << nl;
	cout << typeid(roundf((float)42)).name() << nl2;
	
	cout << roundf(42.42) << nl;
	cout << roundf(42.42f) << nl2;
	
	cout << roundf(42.4242) << nl;
	cout << roundf(42.4242f) << nl2;
	
	cout << roundf(3.1415926535) << nl;
	cout << roundf(3.1415926535f) << nl;
	cout << typeid(roundf(3.1415926535)).name() << nl2;

}
