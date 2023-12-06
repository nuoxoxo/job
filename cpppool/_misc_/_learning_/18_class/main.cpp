#include "iostream"

class	Player
{
public:
	int	x, y;
	int	speed;

	// Construct

	Player()
	{
		x = 10;
		y = 42;
		speed = -1;
	}

	// Destruct ( *remember curly braces {} )

	virtual ~Player()
	{
		std::cout << '(' << __PRETTY_FUNCTION__ << " called) \n";
	}

	void	Move(int dx, int dy)
	{
		std::cout << "Move(dx: " << dx << ", dy: " << dy << ") \n\n";
		x += speed * dx;
		y += speed * dy;
	}

	void	Show()
	{
		std::cout << "Position:  " << x << ' ' << y << '\n';
		std::cout << "Speed(" << speed << ')' << '\n';
		std::cout << std::endl;
	}

};

//	Drive

int	main()
{
	/*
	(object)	(instance)
	*/

	Player		p1;

	// Values assignment is moved inside Class definition

	/*
	p1.x = 10;
	p1.y = 42;
	p1.speed = -1;
	*/

	p1.Show();

	p1.Move(1, 2);
	p1.Show();

	p1.Move(-10, -11);
	p1.Show();
}
