#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	double a, b;

	printf( "Gimme A : " );
	scanf( "%lf", & a );
	printf( "Gimme B : " );
	scanf( "%lf", & b );
	printf( "fmax has spoken : % g\n", fmax( a, b ) );
}
