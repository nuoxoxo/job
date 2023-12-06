#include "iostream"
#include "iomanip"

using	namespace std;

int	main()
{
	float	f;
	int	places = 20;
	f = 3.1415926534;
	cout << f << "\n";
	//cout.precision(places);
	//cout << std::fixed << f << endl;
	cout << std::fixed << std::setprecision(places);
	cout << f << endl;
}
