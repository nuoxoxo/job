#include "iostream"
#include "iomanip"
#include "color.hpp"

using namespace std;

void	precision_float_double(string&, int, float, double);

int	main()
{
	float	numf, numf2, f3pt3, f5pt5;
	double	numdb, numdb2, db3pt3, db5pt5;
	string	lhs, lhs2, lhs3, lhs5;

	numdb = 42.42;
	numf = 42.42;
	lhs = "42.42";

	numdb2 = 196883.196883;
	numf2 = 196883.196883;
	lhs2 = "196883.196883";

	db3pt3 = 123.321;
	f3pt3 = 123.321;
	lhs3 = "123.321";

	db5pt5 = 12345.54321;
	f5pt5 = 12345.54321;
	lhs5 = "12345.54321";

	int N = 12 + 2;
	int i = -1;
	while (++i < N)
	{
		// precision_float_double(lhs, i, numf, numdb); // testing 42.42
		// precision_float_double(lhs2, i, numf2, numdb2); // testing monster
		// precision_float_double(lhs3, i, f3pt3, db3pt3); // testing 123.-
		precision_float_double(lhs5, i, f5pt5, db5pt5); // testing 12345.-
		if (i ^ N - 1)
			cout << '-' << nl2;
	}

	/*precision_float_double(lhs, 2, numf, numdb);
	precision_float_double(lhs2, 2, numf2, numdb2);
	precision_float_double(lhs, 4, numf, numdb);
	precision_float_double(lhs2, 4, numf2, numdb2);
	precision_float_double(lhs, 6, numf, numdb);
	precision_float_double(lhs2, 6, numf2, numdb2);
	precision_float_double(lhs, 10, numf, numdb);
	precision_float_double(lhs2, 10, numf2, numdb2);*/
	
}

void	precision_float_double(string& lhs, int p, float numf, double numdb)
{
	cout << "float/double: ";
	cout << cyan << lhs << rest << nl;
	cout << yell "Set precision: " << p << rest << nl;
	if (p == 6 || p == 2*6 || p == 2*6+1)
		cout << cyan << "(bad precision around 6 and 2*6)" << rest << nl;
	cout << "float\t" << std::setprecision(p) << std::fixed << numf << nl;
	cout << "double\t" << std::setprecision(p) << std::fixed << numdb << nl2;
}
