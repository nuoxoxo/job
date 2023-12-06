/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nxu              ...   ::::::::.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float    get_sign(Point, Point, Point);

/*
--------------------------------------
        @ (x1, y1)


            
            *

                        @ (x2, y2)


    @ (x3, y3)
--------------------------------------
*/


bool bsp( Point const a, Point const b, Point const c, Point const to_check)
{
    bool    has_same_sign;
    float   s1, s2, s3;
    
    s1 = get_sign(to_check, a, b);
    s2 = get_sign(to_check, b, c);
    s3 = get_sign(to_check, c, a);

    if (!s1 || !s2 || !s3)
        return false;

    /*has_same_sign = (
        (s1 < 0 || s2 < 0 || s3 < 0) ||
        (s1 > 0 || s2 > 0 || s3 > 0)
    );*/


    has_same_sign = (
        (s1 < 0 && s2 < 0 && s3 < 0) ||
        (s1 > 0 && s2 > 0 && s3 > 0)
    );

    return (has_same_sign);
}


static float    get_sign(Point p1, Point p2, Point Ref)
{
    //  Formula
    //      (x1 - x) * 
    //      (y2 - y)
    //          subtract
    //      (x2 - x) * 
    //      (y1 - y)

    float res = 
        (p1.getX().toFloat() - Ref.getX().toFloat()) *
        (p2.getY().toFloat() - Ref.getY().toFloat())
        -
        (p2.getX().toFloat() - Ref.getX().toFloat()) *
        (p1.getY().toFloat() - Ref.getY().toFloat())
    ;

    //  Debugger
    //      std::cout << p1.getX() << ' ' << p1.getY() << std::endl;
    //      std::cout << p2.getX() << ' ' << p2.getY() << std::endl;
    //      std::cout << Ref.getX() << ' ' << Ref.getY() << std::endl;
    //      std::cout << res << std::endl;

    return (res);
}

