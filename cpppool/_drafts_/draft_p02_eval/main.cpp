/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/12 09:29:11 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Fixed.hpp"
# include "cassert"
# include "cmath"



// Comparison

static void	Unit_Test_inequality_assert_right(Fixed& l, Fixed& r, int & No);
static void	Unit_Test_inequality_assert_wrong(Fixed& l, Fixed& r, int & No);
static void	Unit_Test_equality(Fixed& l, Fixed& r, int & No);
static void	Unit_Test_inequality(void);


// ++ / -- (postfix & prefix)

static void	Unit_Test_increm_decrem(void);


// Arithmetic int

static void	Unit_Test_arithmetic_printer_int__(Fixed & res, int & res2);
static void	Unit_Test_arithmetic_int__(void);


// Arithmetic float

static void	Unit_Test_arithmetic_printer__(Fixed & res, float & res2);
static void	Unit_Test_arithmetic_float__(void);


// Min max element

static void	Unit_Test_min_max__(void);


int	main( void )
{
	Unit_Test_inequality();
	Unit_Test_arithmetic_float__();
	Unit_Test_arithmetic_int__();
	Unit_Test_increm_decrem();
	Unit_Test_min_max__();

	// provided by subject
	{
		Fixed	a;
		Fixed	const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	} 
	
	// ft_test_final();
	
	std::cout 
	<< YELL
	<< "{{\n\tFor implementation details of Fixed(),\n\t"
	<< "please check out the Python code.\n\n\t"
	<< "https://github.com/nuoxoxo/fixed_py3_demo\n}}\n\n\n"
	<< REST;

}


//	++ / -- (postfix & prefix)
static void	Unit_Test_increm_decrem(void)
{
	Fixed F;

	std::cout << GREEN "current: " << F << REST << " (we are inside " << __FUNCTION__ << ")\n";
	
	F++;
	std::cout << GREEN "Number++\t" REST << std::endl;
	std::cout << GREEN "current:\t" << F << REST << std::endl;
	
	std::cout << GREEN "++Number\t" << ++F << REST << std::endl;
	std::cout << GREEN "current:\t" << F << REST << std::endl;
	
	F--;
	std::cout << GREEN "Number--\t" REST << std::endl;
	std::cout << GREEN "current:\t" << F << REST << std::endl;
	
	std::cout << GREEN "--Number\t" << --F << REST << std::endl;
	std::cout << GREEN "current:\t" << F << REST << std::endl;

	std::cout << REST;
	std::cout << "\n(" << __FUNCTION__ << " ends) \n" << std::endl;
}

//	Min Max elements
static void	Unit_Test_min_max__(void)
{
	{
		Fixed	const Monster_L(196);
		Fixed	const Monster_R(883);
	
		std::cout << GREEN << __FUNCTION__ << REST << std::endl;
		std::cout << GREEN "testing const: " REST << 196 << " vs " << 883 << std::endl;

		std::cout << "Min: " << Fixed::min(Monster_L, Monster_R) << std::endl;
		std::cout << "Max: " << Fixed::max(Monster_L, Monster_R) << std::endl;
		assert(Monster_L == Fixed::min(Monster_L, Monster_R));
		assert(Monster_R == Fixed::max(Monster_L, Monster_R));
	}
	{
		Fixed	const pi (3.14159265359f);
		Fixed	const tau(6.28318530718f);
	
		std::cout << GREEN << __FUNCTION__ << REST << std::endl;
		std::cout << GREEN "testing const: " REST << pi << " vs " << tau << std::endl;
		
		std::cout << "Min: " << Fixed::min(pi, tau) << std::endl;
		assert(pi == Fixed::min(pi, tau));

		std::cout << "Max: " << Fixed::max(pi, tau) << std::endl;
		assert(tau == Fixed::max(pi, tau));
	}
		{
		Fixed	const Monster_L(196);
		Fixed	const Monster_R(883);
	
		std::cout << GREEN << __FUNCTION__ << REST << std::endl;
		std::cout << GREEN "testing non-const: " REST << 196 << " vs " << 883 << std::endl;

		std::cout << "Min: " << Fixed::min(Monster_L, Monster_R) << std::endl;
		std::cout << "Max: " << Fixed::max(Monster_L, Monster_R) << std::endl;
		assert(Monster_L == Fixed::min(Monster_L, Monster_R));
		assert(Monster_R == Fixed::max(Monster_L, Monster_R));
	}
	{
		Fixed	pi (3.14159265359f);
		Fixed	tau(6.28318530718f);
	
		std::cout << GREEN << __FUNCTION__ << REST << std::endl;
		std::cout << GREEN "testing non-const: " REST << pi << " vs " << tau << std::endl;

		std::cout << "Min: " << Fixed::min(pi, tau) << std::endl;
		assert(pi == Fixed::min(pi, tau));

		std::cout << "Max: " << Fixed::max(pi, tau) << std::endl;
		assert(tau == Fixed::max(pi, tau));
	}
	
	std::cout << "\n(" << __FUNCTION__ << " ends) \n" << std::endl;
}


//	Tests for Comparison Operators

static void	Unit_Test_inequality_assert_right(Fixed& l, Fixed& r, int & No)
{
	std::cout << "Comparing " << l << ' ' << r << std::endl;

	{
		if (l < r)	std::cout << "Test " << No++ << " on `<` " << PASS << std::endl;
		else		std::cout << "Test " << No++ << " on `<` " << FAIL << std::endl;
		
		assert(l < r);
	}
	{
		if (r > l)	std::cout << "Test " << No++ << " on `>` " << PASS << std::endl;
		else		std::cout << "Test " << No++ << " on `>` " << FAIL << std::endl;
		
		assert(r > l);
	}
	{
		if (l != r)	std::cout << "Test " << No++ << " on `!=` " << PASS << std::endl;
		else		std::cout << "Test " << No++ << " on `!=` " << FAIL << std::endl;
		
		assert(l != r);
	}
	
	std::cout << "\n(" << __FUNCTION__ << " ends) \n" << std::endl;
}

static void	Unit_Test_inequality_assert_wrong(Fixed& l, Fixed& r, int & No)
{
	std::cout << "Comparing " << l << ' ' << r << std::endl;

	{
		if (l < r)	std::cout << "Test " << No++ << " on `<` " << PASS << std::endl;
		else		std::cout << "Test " << No++ << " on `<` " << FAIL << std::endl;
	
		assert(!(l < r));
	}
	{
		if (r > l)	std::cout << "Test " << No++ << " on `>` " << PASS << std::endl;
		else		std::cout << "Test " << No++ << " on `>` " << FAIL << std::endl;
		
		assert(!(r > l));
	}
	{
		if (l != r)	std::cout << "Test " << No++ << " on `!=` " << PASS << std::endl;
		else		std::cout << "Test " << No++ << " on `!=` " << FAIL << std::endl;
		
		assert(!(l != r));
	}

	std::cout << "\n(" << __FUNCTION__ << " ends) \n" << std::endl;
}

static void	Unit_Test_equality(Fixed& l, Fixed& r, int & No)
{
	std::cout << "Comparing " << l << ' ' << r << std::endl;
	{
		if (l == r)	std::cout << "Test " << No++ << " on `==` " << PASS << std::endl;
		else		std::cout << "Test " << No++ << " on `==` " << FAIL << std::endl;

		assert(l == r);
	}
	{
		if (l != r)	std::cout << "Test " << No++ << " on `!=` " << FAIL << std::endl;
		else		std::cout << "Test " << No++ << " on `!=` " << PASS << std::endl;
	
		assert(!(l != r));
	}
	{
		if (l <= r)	std::cout << "Test " << No++ << " on `<=` " << PASS << std::endl;
		else		std::cout << "Test " << No++ << " on `<=` " << FAIL << std::endl;
	
		assert(l <= r);
	}
	{
		if (l >= r)	std::cout << "Test " << No++ << " on `>=` " << PASS << std::endl;
		else		std::cout << "Test " << No++ << " on `>=` " << FAIL << std::endl;
	
		assert(l >= r);
	}

	std::cout << "\n(" << __FUNCTION__ << " ends) \n" << std::endl;
}

static void	Unit_Test_inequality(void)
{
	Fixed	a(3.14f), aa(3.15f);
	Fixed	b(6.283f), bb(6.284f); // tau
	Fixed	t(6.2831f), tt(6.2832f); // tau // precision limit at end of decimal place
	Fixed	c(196883), d = c;
	int		No = 0;

	// primary

	Unit_Test_inequality_assert_right(a, aa, No); // 2 decimal places precision
	Unit_Test_inequality_assert_right(b, bb, No); // 3 decimal places precision
	Unit_Test_inequality_assert_wrong(t, tt, No); // 4 decimal places precision
	Unit_Test_inequality_assert_right(a, b, No); // Pi vs. Tau
	Unit_Test_equality(c, d, No); // the monster vs. its copy
	
	// additional

	if (b != c)	std::cout << "Test " << No++ << " on `!=` " << PASS << std::endl;
	else		std::cout << "Test " << No++ << " on `!=` " << FAIL << std::endl;
	
	assert(b != c);
	
	std::cout << "\n(" << __FUNCTION__ << " ends) \n" << std::endl;
}


//	Tests (int) for Arithmetic Operators

static void	Unit_Test_arithmetic_printer__(Fixed & res, float & res2)
{
	std::cout << GREEN << res << " vs. " << res2 << REST << std::endl;
}

static void	Unit_Test_arithmetic_float__(void)
{
	float	p = 3.14f, t = 6.28f;
	Fixed	l(p), r(t);
	Fixed	res;
	float	res2;

	// std::cout << std::boolalpha;

	{
		res = l + r;
		res2 = p + t;
		Unit_Test_arithmetic_printer__(res, res2);
		assert(res == res2);
	}
	{
		res = r - l;
		res2 = t - p;
		Unit_Test_arithmetic_printer__(res, res2);
		assert(res == res2);
	}
	{
		res = l * r;
		res2 = p * t;
		Unit_Test_arithmetic_printer__(res, res2);
		assert(res != res2);
	}
	{
		res = l / r;
		res2 = p / t;
		Unit_Test_arithmetic_printer__(res, res2);
		assert(res == res2);
	}
	{
		res = r / l;
		res2 = t / p;
		Unit_Test_arithmetic_printer__(res, res2);
		assert(res == res2);
	
	}
	
	std::cout << "\n(" << __FUNCTION__ << " ends) \n" << std::endl;
}


//	Tests (float) for Arithmetic Operators

static void	Unit_Test_arithmetic_printer_int__(Fixed & res, int & res2)
{
	std::cout << GREEN << res << " vs. " << res2 << REST << std::endl;
}

static void	Unit_Test_arithmetic_int__(void)
{
	int		p = 196, t = 883, res2;
	float	res3;
	Fixed	l(p), r(t);
	Fixed	res;

	// std::cout << std::boolalpha;
	{
		res = l + r;
		res2 = p + t;
		Unit_Test_arithmetic_printer_int__(res, res2);
		assert(res == res2);
	}
	{
		res = r - l;
		res2 = t - p;
		Unit_Test_arithmetic_printer_int__(res, res2);
		assert(res == res2);
	}
	{
		res = l * r;
		res2 = p * t;
		Unit_Test_arithmetic_printer_int__(res, res2);
		assert(res == res2);
	}
	{
		res = l / r;
		res3 = (float)p / (float)t;
		Unit_Test_arithmetic_printer__(res, res3);
		assert(res == res3);
	}
	{
		res = r / l;
		res3 = (float)t / (float)p;
		Unit_Test_arithmetic_printer__(res, res3);
		assert(res == res3);
	}
	
	std::cout << "\n(" << __FUNCTION__ << " ends) \n" << std::endl;
}
