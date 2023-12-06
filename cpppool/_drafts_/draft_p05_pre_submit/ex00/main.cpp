#include "_Cpp05_.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	int	count = 0;
	
	std::cout
	<< nl GREEN ":::::::::::: tests start :::::::::::: \n" RESET nl2;
	
	{
		// % nofunc()
		// % try (nofunc()) catch(error) {console.log('here')}
		// % try (nofunc()) catch(e) {console.log(e)}
		// % try:\ print(iota) except print(':-D')
	}
	{
		Bureaucrat	alex("Alex", 21);
		Bureaucrat	eric(alex);
		Bureaucrat	oscar("Oscar", 42);

		std::cout << alex << eric << oscar << nl;
		
		alex = oscar; // only non const member attributes swapped

		std::cout << alex << eric << oscar;

	}	

	print_ending(++count, "& and =, constructors, ostream");
	
	{
		Bureaucrat	*anonymous = new Bureaucrat();

		std::cout << anonymous;

		try
		{
			anonymous->gradeDown();
		}
		catch (std::exception & e)
		{
			std::cout << e.what();
		}

		delete anonymous;
	}
	
	print_ending(++count);
	
	{
		try {
			Bureaucrat jeffe("Jeffe", -1);	
			std::cout << jeffe;
		} catch (std::exception & e) {
			std::cout << e.what();
		}
	}
	
	print_ending(++count, "grade < 0");
	
	{
		try {
			Bureaucrat jeffe("Jeffe", 1);	
			std::cout << jeffe;
		} catch (std::exception & e) {
			std::cout << e.what();
		}
		
		try {
			Bureaucrat jeffe("Jeffe", 1);	
			jeffe.gradeUp();
			std::cout << jeffe;
		} catch (std::exception & e) {
			std::cout << e.what();
		}
	}
	
	print_ending(++count, "decrement");
	
	{
		try {
			Bureaucrat jorge("Jorge", 150);
			std::cout << jorge;
		} catch (std::exception & e) {
			std::cout << e.what();
		}
		
		try {
			Bureaucrat jorge("Jorge", 149);
			std::cout << jorge;
			jorge.gradeDown();
			std::cout << jorge;
			jorge.gradeDown();
			std::cout << jorge;
		} catch (std::exception & e) {
			std::cout << e.what();
		}
	}
	
	print_ending(++count, "increment");
	
	{
		try {
			Bureaucrat rojas_("Rojas", 150);
			Bureaucrat rojas(rojas_);
			std::cout << rojas;;
		} catch (std::exception & e) {
			std::cout << e.what();
		}
		
		try {
			Bureaucrat rojas_("Rojas", 149);	
			Bureaucrat rojas(rojas_);
			std::cout << rojas;
			rojas.gradeDown();
			std::cout << rojas;
			rojas.gradeDown();
			std::cout << rojas;
		} catch (std::exception & e) {
			std::cout << e.what();
		}
		
		// std::cout << rojas_; // out of scope
		// std::cout << rojas; // out of scope
	}
	
	print_ending(++count, "idem + copy constr");
	
	{
		int	level = 5;

		try {
			Bureaucrat mec("mec", level);
			
			std::cout << mec;
			
			for (int i=level-1; i; --i) {
				mec.gradeUp();
			}
			std::cout << mec;
		} catch (std::exception & outburst) {
			std::cout << outburst.what();
		}
	}
	
	print_ending(++count, "for loop");
}
