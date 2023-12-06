#include "iostream"

#define ylo "\033[33m"
#define cyn "\033[36m"
#define noc "\033[0m"

//	Define one Class & one Struct 

class	Player_Class
{
public:
	int	x, y;
	int	speed;

	// Construct

	Player_Class()
	{
		x = 42;
		y = 10;
		speed = -1;
	}

	// Destruct ( *remember curly braces {} )

	~Player_Class()
	{
		std::cout << "(" ylo << __PRETTY_FUNCTION__ << noc " called) \n";
	}

	void	Move(int dx, int dy)
	{
		std::cout << "(" ylo << __PRETTY_FUNCTION__ << noc " called) \n";
		std::cout << "Move(dx: " << dx << ", dy: " << dy << ") \n";
		std::cout << "Speed(" << speed << ") \n\n";
		x += speed * dx;
		y += speed * dy;
	}

	void	Show()
	{
		std::cout << "(" ylo << __PRETTY_FUNCTION__ << noc " called) \n";
		std::cout << "Position:  " << x << ' ' << y << '\n';
		std::cout << std::endl;
	}

};

struct	Player_Struct // (we deliberately did not specify visibility field)
{
	int	x, y;
	int	speed;

	// Same constructor

	Player_Struct()
	{
		x = 10;
		y = 42;
		speed = -1;
	}

	// Same destruct

	~Player_Struct()
	{
		std::cout << "(" cyn << __PRETTY_FUNCTION__ << noc " called) \n";
	}

	void	Move(int dx, int dy)
	{
		std::cout << "(" cyn << __PRETTY_FUNCTION__ << noc " called) \n";
		std::cout << "Move(dx: " << dx << ", dy: " << dy << ") \n";
		std::cout << "Speed(" << speed << ") \n\n";
		x += speed * dx;
		y += speed * dy;
	}

	void	Show()
	{
		std::cout << "(" cyn << __PRETTY_FUNCTION__ << noc " called) \n";
		std::cout << "Position:  " << x << ' ' << y << '\n';
		std::cout << std::endl;
	}

};

//	Drive

int	main()
{
	Player_Class	p1;
	Player_Struct	p2;

	// p1 (class) demo

	p1.Show();

	p1.Move(1, 2);
	p1.Show();

	p1.Move(-10, -11);
	p1.Show();

	// p2 (struct) demo

	std::cout << "- \n" << std::endl;

	p2.Show();

	p2.Move(1, 2);
	p2.Show();

	p2.Move(-10, -11);
	p2.Show();
}
