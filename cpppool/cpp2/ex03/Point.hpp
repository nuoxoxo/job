#ifndef POINT_HPP
# define POINT_HPP

# include "iostream"
# include "cmath"
# include "Fixed.hpp"

class   Point
{

private:
    const Fixed coor_x;
    const Fixed coor_y;

public:
    // Canon
    
    Point(); // default 
    ~Point(); // destr

    Point(Point const & ); // copy constr
    /// (`Point const` notation dictated by subject)
    
    Point(const Fixed, const Fixed); // assignment constr


    // Overload =
    
    Point & operator = (Point const &);


    // Getter
    
    Fixed getX() const;
    Fixed getY() const;
    

    // (Nothing else)

};

bool    bsp(Point const, Point const, Point const, Point const); // `Point const` not `const Point`

#endif