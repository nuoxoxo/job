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

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include "CPP08X00.hpp"
# include "algorithm"

template<typename T>
typename T::iterator	easyfind(T arr, int val)
{
	typename T::iterator	it;

	it = std::find(arr.begin(), arr.end(), val);

	if (it == arr.end())
		std::cout << LOWKEY notfound << val << nl2 RESET;
	return (it);
}

template<typename T>
typename T::iterator	easyfind(T arr, std::string val)
{

	typename T::iterator	it;

	it = std::find(arr.begin(), arr.end(), val);

	if (it == arr.end())
		std::cout << LOWKEY notfound << val << nl2 RESET;
	return (it);
}

// should not return `*it`
/*
template<typename T>

int	easyfind(T arr, int val)
{
	typename T::iterator	it;

	it = std::find(a.begin(), a.end(), val);
	
	if (it == a.end())
        	throw std::exception();
	return (*it);
}
*/


#endif
