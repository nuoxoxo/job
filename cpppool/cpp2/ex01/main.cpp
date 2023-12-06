/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/12 09:17:09 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Fixed.hpp"

int		main( void )
{
	// Some test
	
	/*
	Fixed	pi(3.1415926f);
	
	pi.toInt();
	std::cout << pi << nl;
	*/


	// Subject test

	Fixed		a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// More test
	
	/*

	Fixed	test(42);
	
	std::cout << test << nl;
	
	Fixed	test_ftoi(369.963f);
	test_ftoi.toInt();
	std::cout << test_ftoi << nl;

	Fixed	test_monster(196.883f);
	test_monster.toInt();
	std::cout << test_monster << nl;
	
	*/

	return 0;
}
