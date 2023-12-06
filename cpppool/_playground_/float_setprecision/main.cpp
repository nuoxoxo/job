#include "iostream"
#include "iomanip"
#include "color.hpp"

using namespace std;

void	precision_float_double(string, int, float, double);

int	main()
{
	float	numf, numf2;
	double	numdb, numdb2;

	numf = 3.14159265358979;
	numf2 = 1.0f / 3.0f;
	
	numdb = 3.14159265358979;
	numdb2 = (double)1.0 / (double)3.0;
		
	precision_float_double("3.14159265358979", 0, numf, numdb);
	precision_float_double("1 / 3", 0, numf2, numdb2);

	precision_float_double("3.14159265358979", 1, numf, numdb);
	precision_float_double("1 / 3", 1, numf2, numdb2);

	precision_float_double("3.14159265358979", 2, numf, numdb);
	precision_float_double("1 / 3", 2, numf2, numdb2);

	precision_float_double("3.14159265358979", 3, numf, numdb);
	precision_float_double("1 / 3", 3, numf2, numdb2);
	
	precision_float_double("3.14159265358979", 12, numf, numdb);
	precision_float_double("1 / 3", 12, numf2, numdb2);

	precision_float_double("3.14159265358979", 20, numf, numdb);
	precision_float_double("1 / 3", 20, numf2, numdb2);
}

void	precision_float_double(string lhs, int p, float numf, double numdb)
{
	cout << yell "set precision: " << p << rest << nl;
	cout << cyan << lhs << rest << nl;
	cout << "float\t" << std::setprecision(p) << numf << nl;
	cout << "double\t" << std::setprecision(p) << numdb << nl2;
}
