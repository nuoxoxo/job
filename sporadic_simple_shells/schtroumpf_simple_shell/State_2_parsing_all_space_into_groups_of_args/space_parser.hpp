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

#include "string.h"
#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"
#include "readline/readline.h"
#include "readline/history.h"
#include "sys/types.h"
#include "sys/wait.h"

#define maxcommands 1000
#define maxlistsize 100

#define _yellow	"\x1b[33m"
#define _red	"\x1b[31m"
#define _green	"\x1b[32m"
#define _blue	"\x1b[34m"
#define _mag	"\x1b[35m"
#define _cyan	"\x1b[36m"
#define _reset	"\x1b[0m"
