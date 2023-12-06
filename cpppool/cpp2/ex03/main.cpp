/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/12 09:37:25 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Point.hpp"


static void	print_3pts(Point const, Point const, Point const, Point const);


/*
 * 
 * Check out this demo that I wrote:
 * 
 * 
 * https://editor.p5js.org/nuoxoxo/sketches/WT-94Rgmm
 *
 *
*/


int main()
{
	bool	flag;

	// Test 1
	{
		Point const	p1(0, 0);
		Point const	p2(10, 30);
		Point const	p3(20, 0);

		//		. b {10,30}
		//             / \
		//            /   \
		//           /     \
		//          /   . P {10, 15}
		//         /         \
		//  a {0,0} ---------- c {20,0} 

		Point const	P(10, 15);
		
		print_3pts(p1, p2, p3, P);
		flag = bsp(p1, p2, p3, P);

		if (flag)
		{
			std::cout << "Result  \t" GREEN "Yes it is." REST;
		}
		else
		{
			std::cout << "Result  \t" RED "No it is not." REST;
		}
		std::cout << nl2;

		assert(flag);
	}
	// Test 2
	{
		Point const	p1(0, 0);
		Point const	p2(10, 30);
		Point const	p3(20, 0);

		//		.	b, P {10,30} (same coor)
		//             / \
		//            /   \
		//           /     \
		//          /       \
		//         /         \
		//  a {0,0} ---------- c {20,0}

		Point const	P(10, 30);
		
		print_3pts(p1, p2, p3, P);
		flag = bsp(p1, p2, p3, P);

		if (flag)
		{
			std::cout << "Result  \t" GREEN "Yes it is." REST;
		}
		else
		{
			std::cout << "Result  \t" RED "No it is not." REST;
		}
		std::cout << nl2;

		assert(! flag);
	}
	// Test 3
	{
		Point const	p1(0, 0);
		Point const	p2(10, 30);
		Point const	p3(20, 0);

		//		b
		//		.		. P
		//             / \
		//            /   \
		//           /     \
		//          /       \
		//         /         \
		//  a {0,0} ---------- c {20,0} 


		Point const	P(1000, 3000);
		
		print_3pts(p1, p2, p3, P);
		flag = bsp(p1, p2, p3, P);
		
		if (flag)
		{
			std::cout << "Result  \t" GREEN "Yes it is." REST;
		}
		else
		{
			std::cout << "Result  \t" RED "No it is not." REST;
		}
		std::cout << nl2;

		assert(! flag);
	}
	// test 4
	{
		Point const	p1(-4, 0);
		Point const	p2(12, 8);
		Point const	p3(12, 0);

		//
		//                                     . P
		//
		//                        (8, 6) .     |
		// 
		//                       .             |
		//
		//                . (2, 3)             |
		//
		//         .                           |
		//  a {-4,0} -------------------- c {12,0} 

		// somewhere on the slope
		{
			Point const	P(2, 3);
		
			print_3pts(p1, p2, p3, P);
			flag = bsp(p1, p2, p3, P);

			if (flag)
			{
				std::cout << "Result  \t" GREEN "Yes it is." REST;
			}
			else
			{
				std::cout << "Result  \t" RED "No it is not." REST;
			}
			std::cout << nl2;
			
			assert(! flag);
		
		}
		// idem with +.1 on x-axis thus inside
		{
			Point const	P(2.1f, 3);
			
			print_3pts(p1, p2, p3, P);
			flag = bsp(p1, p2, p3, P);
			if (flag)
			{
				std::cout << "Result  \t" GREEN "Yes it is." REST;
			}
			else
			{
				std::cout << "Result  \t" RED "No it is not." REST;
			}
			std::cout << nl2;
		
			assert(flag);

		}
		// idem with +.1 on y-axis thus not inside
		{
			Point const	P(2, 3.1f);
			
			print_3pts(p1, p2, p3, P);
			flag = bsp(p1, p2, p3, P);
			
			if (flag)
			{
				std::cout << "Result  \t" GREEN "Yes it is." REST;
			}
			else
			{
				std::cout << "Result  \t" RED "No it is not." REST;
			}
			std::cout << nl2;
		
			assert(! flag);

		}
		// idem with -.1 in y thus inside
		{
			Point const	P(2, 2.9f);
			
			print_3pts(p1, p2, p3, P);
			flag = bsp(p1, p2, p3, P);
			if (flag)	
			{
				std::cout << "Result  \t" GREEN "Yes it is." REST;
			}
			else
			{
				std::cout << "Result  \t" RED "No it is not." REST;
			}
			std::cout << nl2;
		
			assert(flag);
		
		}
		// another point on slope
		{
			Point const	P(8.00f, 6.000000f);
		
			print_3pts(p1, p2, p3, P);
			flag = bsp(p1, p2, p3, P);

			if(flag) {
				std::cout << "Result  \t" GREEN "Yes it is." REST;
			} else {
				std::cout << "Result  \t" RED "No it is not." REST;
			}
			std::cout << nl2;
		
			assert(! flag);

		}
		// random point
		{
			Point const	P(11.75001f, 3.1415926f);
		
			print_3pts(p1, p2, p3, P);
			flag = bsp(p1, p2, p3, P);

			if (flag)
			{
				std::cout << "Result  \t" GREEN "Yes it is." REST;
			}
			else
			{
				std::cout << "Result  \t" RED "No it is not." REST;
			}
			std::cout << nl2;

			assert(flag);

		}
		// random point in the 2nd Quadrant
		{
			Point const	P(-1.97531f, 0.987654f);
		
			print_3pts(p1, p2, p3, P);
			flag = bsp(p1, p2, p3, P);

			if (flag)
			{
				std::cout << "Result  \t" GREEN "Yes it is." REST;
			}
			else
			{
				std::cout << "Result  \t" RED "No it is not." REST;
			}
			std::cout << nl2;

			assert(flag);

		}
		
	}
	std::cout << "check out my demo for this algo: \n\n";
	std::cout << "\thttps://editor.p5js.org/nuoxoxo/sketches/WT-94Rgmm" << "\n\n";
}


// helper


static void print_3pts(Point const p1, Point const p2, Point const p3, Point const P)
{
	std::cout << CYAN "Point 1 \ta " << REST "{"
	<< p1.getX().toFloat() << ", " << p1.getY().toFloat() << "} \n";
	std::cout << CYAN "Point 2 \tb " << REST "{" 
	<< p2.getX().toFloat() << ", " << p2.getY().toFloat() << "} \n";
	std::cout << CYAN "Point 3 \tc " << REST "{" 
	<< p3.getX().toFloat() << ", " << p3.getY().toFloat() << "} \n";

	std::cout << YELL "Inspect \tP " << REST "{" 
	<< P.getX().toFloat() << ", " << P.getY().toFloat() << "} \n";
}
