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


// Default

Point::Point(void): coor_x(), coor_y()
{
    // std::cout << inside << __FUNCTION__ << ' '
    // << YELL " Default constructor" << called REST;
}

Point::Point(const Fixed newX, const Fixed newY): coor_x(newX), coor_y(newY)
{
    ;;
}

Point::Point(Point const & dummy)
{
    // std::cout << inside << __FUNCTION__ << ' '
    // << YELL "Copy constructor" << called REST;

    *this = dummy;
}

Point::~Point(void)
{
    // std::cout << RED "Destructor" << called REST;
}


// Operator =

Point & Point::operator = (const Point & point)
{
    // this->coor_x = point.coor_x;
    // this->coor_y = point.coor_y;

    (Fixed &) this->coor_x = point.coor_x;
    (Fixed &) this->coor_y = point.coor_y;
    
    return *this;
}


//  Getter

Fixed   Point::getX(void) const { return this->coor_x; }
Fixed   Point::getY(void) const { return this->coor_y; }