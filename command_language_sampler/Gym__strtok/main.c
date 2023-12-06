#include "string.h"
#include "stdio.h"
#include "stdlib.h"

int	main()
{
	//char	s[] = "102*103;K1.2;K0.5";
	//char	s[] = "102*103;;K1.2;;;K0.5;;;   K900";
	char	s[] = "102;103;;12;;;64;;;;512";
	char	sep[] = ";";
	//char	sep[] = " ";
	char	*t;
	
	t = strtok(s, sep);
	while (t)
	{
		t = strtok(NULL, sep);
	}
}
