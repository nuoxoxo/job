#include "stdio.h"

//	enum = a user defined type of named integer identifiers

enum	e_day
{
	SUN,	// each is a const, and has an associated int, ie. SUN = 1
	MON,	// MON = 2, and so on ...
	TUE,
	WED,
	THU,
	FRI,
	SAT,
	RANDOM_DAY_0 = 42,
	RANDOM_DAY_1
};

//	*their values are Integers, not strings

int	main()
{
	enum e_day	d0, d1;

	d0 = RANDOM_DAY_0;
	d1 = RANDOM_DAY_1;
	printf("%d %d \n", d0, d1);
}
