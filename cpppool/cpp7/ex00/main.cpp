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

#include "whatever.hpp"

#define GREEN "\033[0;32m"
#define RESET "\033[0;0m"

int	main()
{
	int	i = -1;

	std::cout << GREEN "Test :: " << ++i << " char" << nl2 RESET;
	{
		char	l = 'a';
		char	r = 'o';

		std::cout << l << " - " << r << nl;
		swap(l, r);
		std::cout << l << " - " << r << nl2;

		std::cout << "max: " << max(l, r) << nl;
		std::cout << "min: " << min(l, r) << nl2;
	}
	std::cout << GREEN "Test :: " << ++i << " string" << nl2 RESET;
	{
		std::string	l = "good morning";
		std::string	r = "vietnam";

		std::cout << l << " - " << r << nl;
		swap(l, r);
		std::cout << l << " - " << r << nl2;

		std::cout << "max: " << ::max(l, r) << nl; // TODO explain
		std::cout << "min: " << ::min(l, r) << nl2;
	}
	std::cout << GREEN "Test :: " << ++i << " int" << nl2 RESET;
	{
		int	l = 42;
		int	r = 1968833;

		std::cout << l << " - " << r << nl;
		swap(l, r);
		std::cout << l << " - " << r << nl2;

		std::cout << "max: " << max(l, r) << nl;
		std::cout << "min: " << min(l, r) << nl2;
	}
	std::cout << GREEN "Test :: " << ++i << " double" << nl2 RESET;
	{
		double	l = 42.42;
		double	r = 3.1415926;

		std::cout << l << " - " << r << nl;
		swap(l, r);
		std::cout << l << " - " << r << nl2;

		std::cout << "max: " << max(l, r) << nl;
		std::cout << "min: " << min(l, r) << nl2;
	}
	std::cout << GREEN "Test :: " << ++i << " float" << nl2 RESET;
	{
		float	l = 42.42f;
		float	r = 3.1415f;

		std::cout << l << " - " << r << nl;
		swap(l, r);
		std::cout << l << " - " << r << nl2;

		std::cout << "max: " << max(l, r) << nl;
		std::cout << "min: " << min(l, r) << nl2;
	}
}
