#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	srand(time(0));
	switch (rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return (0);
	}
}

void	identify(Base* na)
{
	std::cout << __FUNCTION__ << " (Base *): ";
	if (dynamic_cast<A *>(na)) {

		std::cout << "A \n";
	
	} else if (dynamic_cast<B *>(na)) {

		std::cout << "B \n";
	
	} else if (dynamic_cast<C *>(na)) {

		std::cout << "C \n";
	}
	else {

		std::cout << "(something's apparently wrong) \n";
	
	}
}

void	identify(Base& p)
{
	Base	dummy;

	std::cout << __FUNCTION__ << " (Base &): ";
 
	try {

		A	& a = dynamic_cast<A &>(p); // 1st way

		std::cout << "A" << std::endl;
		(void) a;
		return ;

	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	
	try {

		dummy = dynamic_cast<B &>(p); // 2nd way
		std::cout << "B" << std::endl;
		return ;

	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	
	try {

		dummy = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;

	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}
