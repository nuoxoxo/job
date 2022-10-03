/* ************************************************************************** */
/*                                                                            */
/*                            \\             /`/``                            */
/*                            ~\o o_       0 0\                               */
/*                            / \__)      (u  ); _  _                         */
/*                     / \/ \/  /           \  \/ \/ \                        */
/*                    /(   . . )            (         )\                      */
/*                   /  \_____/              \_______/  \                     */
/*                       []  []               [[] [[]    *.                   */
/*                       []] []]              [[] [[]                         */
/*                                                                            */
/* ****************************************************************** nxu *** */

#include "stdio.h"
#include "./../philo.h"	/* sys/time.h included */

int	main(void)
{
	struct timeval		tv;
	struct timezone		zone;

	gettimeofday(& tv, & zone);
	printf("seconds since 1/1/1970: \n");
	printf("\t %lu \t. the current Unix epoch time \n\n", tv.tv_sec);
	printf("usec field (microseconds) : \n");
	printf("\t %d \n\n", tv.tv_usec);
	printf("microsec since 1/1/1970: \n");
	printf("\t %ld \n\n", tv.tv_sec * (int) 1e6 + tv.tv_usec);
	return(0);
}
