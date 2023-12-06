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

#include "unistd.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

int	main(int argc, char **argv)
{
	char		*s, *token;

	if (argc ^ 3)
	{
		/* using fprintf a.k.a. FILE*stream-print-format */
		// fprintf(stderr, "Usage: ./%s  [ string ]  [ delimiter_char ] \n", argv[0]);
		
		/* or just write */
		write(2, "Usage: ", 7);
		write(2, argv[0], (int) strlen(argv[0]));
		write(2, "  [string]  [delimiter]  \n", 26);

		return (1);
	}
	/* dupa uses alloca - *allo*cate and *a*utomatically free */
	//s = strdupa(argv[1]);
	s = strdup(argv[1]);
	if (!s)
		return (1);
	token = strsep(& s, argv[2]); /* 1st parameter should be a malloced string */
	if (!token)
		return (1);
	printf("token: \'%s\' \n", token);
	printf("origin: \'%s\' \n", argv[1]);
	printf("jettisonned: \'%s\' \n", s);
//	free(token);
//	free(s);
	return (0);
}
