/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                             ~  ~  ~  ~  ~    ~                             */
/*                              ~    _ ~ _   o>                               */
/*                             ~  \ / \ / \ /  ~                              */
/*                              ~  ~      ~    ~                              */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                 Template                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* *********************  ʕ • ᴥ•ʔ  mode: todo  (⊙. ⊙ )  ********************* */

#include "iostream"
#include "sstream"
#include "vector"
#include "set"
#include "cstdlib" // rand
#include "easyfind.hpp"
#include "CPP08X00.hpp"

int	main(int c, char **v)
{
	int	target, size, i;

	i = -1;
	size = 1;
	srand(time(0));
	// if (!(size = c ^ 2 ? SIZE : std::stoi(v[1]) % (MAX + 1)))
	// 	size = 1;
	
	if (c == 2)
	{
		int	n;

		std::stringstream(v[1]) >> n;
		size = n % (MAX + 1);
	}

	std::cout << GREEN nl "Test :: " << ++i << " :: find 42" nl2reset;
	{
		std::vector<int>::iterator	it;
		std::vector<int>		v(size, 42);

		target = 42;
		
		it = easyfind(v, target);

		print_target(target);
		print_vector(v);

		std::cout << "it:\t" << &it << nl;
		std::cout << "*it:\t" << *it << nl2;
		/*if (it == v.end())
			std::cout << LOWKEY "iterator now points to _.end()" << nl2 RESET;
		else
			std::cout << "it:\t" << *it << nl2;
		*/
	}
	std::cout << GREEN "Test :: " << ++i << " :: find randint " nl2reset;
	{
		target = (int) rand() % (MAX + MAX);
		
		std::vector<int>::iterator	it;
		std::vector<int>		v;

		int	i = -1;

		while (++i < size)
			v.push_back((int) rand() % (MAX + MAX));

		print_target(target);
		print_vector(v);
		
		it = easyfind(v, target);
		
		std::cout << "it:\t" << &it << nl;
		std::cout << "*it:\t" << *it << nl2;
	}
	std::cout << GREEN "Test :: " << ++i << " :: string vector " nl2reset;
	{
		std::vector<std::string>::iterator	it;
		std::vector<std::string>		v;

		std::string	target;

		v.push_back("Lorem ");
		v.push_back("ipsum ");
		v.push_back("good");
		v.push_back(" morning ");
		v.push_back("vietnam!");

		print_vector(v);	

		target = "good";
		print_target(target);
		it = easyfind(v, target);

		std::cout << "it:\t" << &it << nl;
		std::cout << "*it:\t" << *it << nl2;

		target = "vietnam!";
		print_target(target);
		it = easyfind(v, target);
		
		std::cout << "it:\t" << &it << nl;
		std::cout << "*it:\t" << *it << nl2;
		
		target = "vietnam";
		print_target(target);
		it = easyfind(v, target);
		
		std::cout << "it:\t" << &it << nl;
		// std::cout << "*it:\t" << *it << nl2; // segf fix

		if (it != v.end())
			std::cout << LOWKEY endpoint nl2 RESET;
		else
			std::cout << "it:\t" << *it << nl2;
	}
	std::cout << GREEN "Test :: " << ++i << " :: integer set " nl2reset;
	{
		target = (int) rand() % (MAX + MAX);

		std::set<int>::iterator	it;
		std::set<int>		s;

		int	i = -1;

		while (++i < size)
			s.insert((int) rand() % (MAX + MAX));

		print_target(target);
		print_set(s);

		it = easyfind(s, target);

		std::cout << "it:\t" << &it << nl;
		std::cout << "*it:\t" << *it << nl2;

	}
	std::cout << GREEN "Test :: " << ++i << " :: string set " nl2reset;
	{
		std::string	target;

		std::set<std::string>::iterator	it;
		std::set<std::string>		s;

		s.insert("Lorem ");
		s.insert("ipsum ");
		s.insert("good");
		s.insert(" morning ");
		s.insert("vietnam!");

		print_set(s);	
		
		target = "good";
		print_target(target);
		it = easyfind(s, target);
		
		std::cout << "it:\t" << &it << nl;
		std::cout << "*it:\t" << *it << nl2;
		
		target = "vietnam!";
		print_target(target);
		it = easyfind(s, target);
		
		std::cout << "it:\t" << &it << nl;
		std::cout << "*it:\t" << *it << nl2;
		
		target = "vietnam";
		print_target(target);
		it = easyfind(s, target);
		
		std::cout << "it:\t" << &it << nl2;
		// std::cout << "*it:\t" << *it << nl2; // segf fix

		if (it != s.end())
			std::cout << LOWKEY endpoint nl2 RESET;
		else
			std::cout << "it:\t" << *it << nl2;
		/*{
			try {std::cout << "it:\t" << *it << nl2;}
			catch (const std::exception & e)
			{std::cout << e.what() << nl2;}
		}*/

	}
}
