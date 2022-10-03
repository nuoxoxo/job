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
#include "unistd.h"
#include "stdlib.h"
#include "fcntl.h"

int	count_char(char *, char);
int	len(char *);
char	*gnl(int);

int	main(int ac, char **v)
{
	int			fd;
	char			*line, c;

	if (ac == 1)
	{
		fd = open("./infile", O_RDONLY);
		line = gnl(fd);
		line[len(line) - 1] = 0;
		c = '\\';
		printf("haystack: %s \nneedle:\t %c \nresult:\t %d \n",
		line, c, count_char(line, c));
	}
	else if (ac == 3)
	{
		line = v[1];
		c = *v[2];
		printf("haystack: %s \nneedle:\t %c \nresult:\t %d \n",
		line, c, count_char(line, c));
	}
	return (0);
}

int	count_char(char *line, char c)
{
	int		i, count;

	count = i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			while (line[++i] && line[i] != '\'');
		if (line[i] == '\"')
			while (line[++i] && line[i] != '\"');
		if (line[i] == c)
			++count;
		if (line[i])
			++i;
	}
	return (count);
}

char	*gnl(int fd)
{
	char		*line;
	char		*p;

	line = malloc((int) 1e4);
	p = line;
	while (read(fd, p, 1) > 0 && *p++ != 10)
		;
	if (p == line)
	{
		free(line);
		return (NULL);
	}
	*p = 0;
	return (line);
}

int	len(char *s)
{
	int		i = 0;

	while (s[i] && ++i)
		;
	return i ;
}
