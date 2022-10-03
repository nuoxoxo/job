#include "get_next_line.h"
#include "fcntl.h"
#include "stdio.h"
#define ss printf("---\n")

int	main(int argc, char *argv[])
{
        char	*line;
	int f, i = 0;
        int T = (argc == 1) ? 0 : atoi(argv[1]);
        int L = (argc == 3) ? atoi(argv[2]) : 16;

	T = T < 8 ? T : 1;
        if (argc == 2) {
            if (T == 3) L = 42;
            if (T == 6) L = 42;
            if (T == 0) L = 8;
            if (T == 2) L = 10;
            if (T == 4) L = 128;
            if (T == 5) L = 512;
	    if (T == 7)	L = 4;
        }
        if (T == 1) f = open("texts/MSP", O_RDONLY);
	if (T == 2) f = open("texts/RT", O_RDONLY);
        if (T == 3) f = open("texts/JG", O_RDONLY);
	if (T == 4) f = open("texts/AOC", O_RDONLY);
	if (T == 5) f = open("texts/AOC5", O_RDONLY);
	if (T == 6) f = open("texts/HEAD", O_RDONLY);
	if (T == 0) f = open("texts/ANM", O_RDONLY);
	if (T == 7) f = open("texts/NO_NL", O_RDONLY);
	ss;
        while( ++i < L + 1 ) {
            line = get_next_line(f);
            printf("# %02d: %s", i, line);
	    if (!line)
                printf("\n");
            else
                free(line);
        }
        ss;
        close(f);
        return 0;
}
