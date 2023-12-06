/*
 *	created on aug 22
 */

#include "iostream"

class	Int
{
	public:
		int	Val;

		Int(void);
		Int(const Int &);
		~Int(void);

		Int operator ++ (int);
		Int & operator ++ (void); // pre

		Int operator -- (int);
		Int & operator -- (void); // pre
};

std::ostream & operator << (std::ostream &, const Int &);

//	drive

int	main()
{
	Int	n;

	std::cout << n++ << std::endl;
	std::cout << n << std::endl;
	std::cout << ++n << std::endl;
}

//

Int::Int() { this->Val = 0; }

Int::~Int() {}

Int::Int(const Int & dummy) { *this = dummy; }

Int	Int::operator ++ (int) // post
{
	Int	temp(*this);

	(*this).Val++;
	return (temp);
}

Int	Int::operator -- (int) // post
{
	Int	temp(*this);

	(*this).Val--;
	return (temp);
}

Int	& Int::operator ++ (void) // pre
{
	this->Val += 1;
	return (*this);
}

Int	& Int::operator -- (void) // pre
{
	this->Val -= 1;
	return (*this);
}

std::ostream & operator << (std::ostream & os, Int const & i)
{ 
	os << i.Val;
	return os;
}
