#include "get_next_line_bonus.h"
#include "fcntl.h"
#include "stdio.h"
#define ss printf("---\n\n")

int	main(int ac, char **v)
{
	if (ac^1 && ac^2)	return 0 ;

        char	*line;
	int	N, p1, p2, p3, i = 0, L = 10;

	if ((N = (ac==1) ? 1 : atoi(v[1])) > 4)	return 0;
	if (N == 1){
		p1 = open("texts/MSP", O_RDONLY);
		p2 = open("texts/ANM", O_RDONLY);
		p3 = open("texts/RT", O_RDONLY);
	} if (N == 2) {
		p1 = open("texts/RT", O_RDONLY);
		p2 = open("texts/JG", O_RDONLY);
		p3 = open("texts/AOC", O_RDONLY);
	} if (N == 3) {
		p1 = open("texts/ANM", O_RDONLY);
		p2 = open("texts/AOC5", O_RDONLY);
		p3 = open("texts/MSP", O_RDONLY);
	} if (N == 4) {
		p1 = open("texts/JG", O_RDONLY);
		p2 = open("texts/AOC", O_RDONLY);
		p3 = open("texts/MSP", O_RDONLY);
	}
	while (++i < L)
	{
		line = get_next_line(p1);
		printf("# %02d: %s", i, line);
	    	if (!line)	printf("\n");
		else		free(line);

		line = get_next_line(p2);
		printf("# %02d: %s", i, line);
	    	if (!line)	printf("\n");
		else		free(line);

		line = get_next_line(p3);
		printf("# %02d: %s", i, line);
	    	if (!line)	printf("\n");
		else		free(line);
		ss;
	}
	close(p1);
	close(p2);
	close(p3);
}
