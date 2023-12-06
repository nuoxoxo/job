#include <cmath>
#include <iomanip>
#include <iostream>
  
using namespace std;
  
int	main()
{
	double	x;

	x = fmax(10.0, 1.0);
	cout << fixed << setprecision(4) << "fmax(10.0, 1.0) = " << x << '\n';

	x = fmax(-10.0, 1.0);
	cout << fixed << setprecision(4) << "fmax(-10.0, 1.0) = " << x << '\n';

	x = fmax(-10.0, -1.0);
	cout << fixed << setprecision(4) << "fmax(-10.0, -1.0) = " << x << '\n';

	return 0;
}
