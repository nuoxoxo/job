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

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include "iostream"

# define nl "\n"
# define nl2 "\n\n"

template<typename T>
void	swap(T & a, T & b)
{
	std::cout << "(" << __FUNCTION__ << " called) " nl;
	
	try {
		T temp = a;
		a = b;
		b = temp;
	}
	catch (std::exception(& e)) {
		std::cerr << e.what() << nl;
		;;
	}
}

template<typename T>
const	T & min(const T & a, const T & b)
{
	// std::cout << __FUNCTION__ << " called" nl2;
	
	try {
		return (a < b ? a : b);
	}
	catch (std::exception(& e)) {
		return (b);
	}
}

template<typename T>
const	T & max(const T & a, const T & b)
{
	// std::cout << __FUNCTION__ << " called" nl2;

	try {
		return (a > b ? a : b);
	}
	catch (std::exception(& e)) {
		return (b);
	}

}

#endif

