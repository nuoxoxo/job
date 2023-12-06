#include "iostream"
#include "string"

///	V2 is vector2

class	V2
{
public:
	float	x;
	float	y;

	//	constr

	V2(float x, float y) : x(x), y(y) {}

	//	below:
	//	'const & other' means const reference to avoid copying
	//	'const' at the end means constant function, which
	//		means not modifying this class, but creating
	//		a new V2 with the result.

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

int	main()
{
	V2	position(4.2f, 4.2f);
	V2	velocity(0.5f, 1.5f);
	V2	gatorade(1.1f, 1.1f);

	V2	res = position._ADD_(velocity._MULT_(gatorade));

	res._V2_PRINT_();

}
