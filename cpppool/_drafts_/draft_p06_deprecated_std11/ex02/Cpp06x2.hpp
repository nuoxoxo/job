#ifndef CPP06X2_HPP
# define CPP06X2_HPP

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# define nl "\n"

Base	*generate(void)
{
	srand(time(0));
	switch (rand() % 3)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (0);
	}
}

void	identify(Base* na)
{
	std::cout << __FUNCTION__ << " (Base *): ";
	
	if (dynamic_cast<A *>(na))
	{
		std::cout << "A";
	}
	else if (dynamic_cast<B *>(na))
	{
		std::cout << "B";
	
	}
	else if (dynamic_cast<C *>(na))
	{
		std::cout << "C";
	}
	else
	{
		std::cout << "(something's apparently wrong)";
	}
	std::cout << " \n";
}

void	identify(Base & p)
{
	Base	dummy;

	std::cout << __FUNCTION__ << " (Base &): ";

	// A

	try
	{
		A & a = dynamic_cast<A &>(p); (void) a; // 1st way
		// dummy = dynamic_cast<B &>(p); // 2nd way

		std::cout << "A \n";
		return ;
	}
	catch (const std::exception & e)
	{
		// std::cerr << "A " << e.what() << nl; // XXX uncomment @ eval
	}

	// B

	try
	{
		// B & b = dynamic_cast<B &>(p); (void) b; // 1st way
		dummy = dynamic_cast<B &>(p); // 2nd way
		
		std::cout << "B \n";
		return ;
	}
	catch (const std::exception & e)
	{
		// std::cerr << "B " << e.what() << nl; // XXX uncomment @ eval
	}

	// C

	try
	{
		C & c = dynamic_cast<C &>(p); (void) c; // 1st way
		// dummy = dynamic_cast<C &>(p); // 2nd way
		
		std::cout << "C \n";
		return ;
	}
	catch (const std::exception & e)
	{
		std::cerr << "C " << e.what() << nl; // XXX uncomment @ eval
	}
}

#endif
