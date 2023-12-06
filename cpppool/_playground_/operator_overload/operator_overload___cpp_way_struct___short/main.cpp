#include "iostream"
#include "iomanip" // print bool
#include "string"

///	V2 is vector2

struct	V2
{
	float	x;
	float	y;

	//	constr

	V2(float x, float y) : x(x), y(y) {}

	//	below:
	//	'const & other' means const reference to avoid copying
	//	'const' at the end means constant function, which
	//		means not modifying this class, but creating
	//		a new V2 with the result.

	V2	operator + (const V2 & other) const
	{
		return _ADD_(other);
	}

	V2	operator * (const V2 & other) const
	{
		return _MULT_(other);
	}

	bool	operator == (const V2 & other) const
	{
		return x == other.x && y == other.y;
	}

	bool	operator != (const V2 & other) const
	{
		return !(*this == other);
	}


	//	we keep the old funcs but add the overloading above

	V2	_ADD_(const V2 & other) const
	{
		return V2(x + other.x, y + other.y);
	}

	V2	_MULT_(const V2 & other) const
	{
		return V2(x * other.x, y * other.y);
	}

	void	_V2_PRINT_(void)
	{
		std::cout << "x: " << this->x << '\n' 
			<< "y: " << this->y << '\n';
	}
};

//	<< operator overloading is defined outside of the V2 class, 
//	coz it has nothing to do with the V2
//	1st param: we need the reference to the existing stream, which is cout
//	2nd param: a V2 reference

std::ostream & operator << (std::ostream & stream, const V2 & other)
{
	stream << "x: " << other.x << '\n'
		<< "y: " << other.y << '\n';

	return stream;
}

int	main()
{
	V2	position(4.2f, 4.2f);
	V2	velocity(0.5f, 1.5f);
	V2	gatorade(1.1f, 1.1f);

	V2	res1 = position._ADD_(velocity._MULT_(gatorade));
	V2	res2 = position + velocity * gatorade; // operator precedence

	//	old printer
	res1._V2_PRINT_();
	//	new way of printing via Overloading the ostream
	std::cout << res2;

	//	the final overloading: '==' & '!='
	std::cout << std::boolalpha;
	std::cout << '\n' << (res1 == res2);
	std::cout << '\n' << (res1 != res2) << std::endl;
}
