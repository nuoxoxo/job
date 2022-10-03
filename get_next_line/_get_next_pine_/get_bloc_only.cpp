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
/* ****************************************************************** nuo *** */

#include "iostream"
#include "fcntl.h"
#include "unistd.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif

#define SEP printf("--\n")

using   namespace std;

int     main(int argc, char *argv[])
{
        char    bloc[100];
        char    *buff;
        int     f, bytes;

        if (!(buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1))))
            return 1;
        if (argc == 1)  f = open("texts/MSP", O_RDONLY);
        if (argc == 2)
        {
            if (stoi(argv[1]) == 1) f = open("texts/MSP", O_RDONLY);
            else                    f = open("texts/RT", O_RDONLY);
        }
        bytes = 1;
        while (bytes && !strchr(bloc, '\n'))
        {
            bytes = read(f, buff, BUFFER_SIZE);
            if (bytes == -1)
            {
                free(buff);
                return (1);
            }
            buff[bytes] = 0;
            if (strlen(bloc) == 1)  strcpy(bloc, buff);
            else                    strcat(bloc, buff);
        }
        SEP;
        printf("%s\n", bloc);
        SEP;

        return 0;
}
