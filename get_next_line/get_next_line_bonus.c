/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ____/__/__ __:__:__ by nuo               #+#    #+#             */
/*   Updated: ____/__/__ __:__:__ by nuo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//	Solution 1: Verbose

char	*get_next_line(int f)
{
	static char	*bloc[(int)1e6];
	char		*line;

	if (f < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bloc[f] = fetch_bloc(f, bloc[f]);
	if (!bloc[f])
		return (NULL);
	line = fetch_line(bloc[f]);
	bloc[f] = regen_bloc(bloc[f]);
	return (line);
}

char	*fetch_bloc(int fd, char *bloc)
{
	char	buff[BUFFER_SIZE + 1];
	int		bytes;

	bytes = 1;
	while (bytes && !sch(bloc))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		buff[bytes] = 0;
		bloc = paste_bloc(bloc, buff);
	}
	return (bloc);
}

char	*paste_bloc(char *bloc, char *buff)
{
	char	*rest;
	int		i;
	int		j;

	if (!bloc)
	{
		bloc = malloc(1);
		if (!bloc)
			return (NULL);
		bloc[0] = 0;
	}
	rest = malloc(1 + len(bloc) + len(buff));
	if (!rest)
		return (NULL);
	i = -1;
	while (bloc[++ i])
		rest[i] = bloc[i];
	j = 0;
	while (buff[j])
		rest[i ++] = buff[j ++];
	rest[i] = 0;
	free(bloc);
	return (rest);
}

char	*fetch_line(char *bloc)
{
	char	*line;
	int		i;

	if (! bloc[0])
		return (NULL);
	i = 0;
	while (bloc[i] && bloc[i] ^ 10)
		i += 1;
	line = malloc(2 + i);
	if (!line)
		return (NULL);
	i = -1;
	while (bloc[++ i] && bloc[i] ^ 10)
		line[i] = bloc[i];
	if (bloc[i] && bloc[i] == 10)
		line[i++] = 10;
	line[i] = 0;
	return (line);
}

char	*regen_bloc(char *bloc)
{
	char	*rest;
	int		size;
	int		i;
	int		j;

	i = 0;
	while (bloc[i] && bloc[i] ^ 10)
		i += 1;
	if (!bloc[i])
	{
		free(bloc);
		return (NULL);
	}
	size = len(bloc) - i;
	rest = malloc(1 + size);
	if (!rest)
		return (NULL);
	j = 0;
	i += 1;
	while (bloc[i])
		rest[j ++] = bloc[i ++];
	rest[j] = 0;
	free(bloc);
	return (rest);
}

//	Solution 2: Golf, cannot pass norm

/*

char	*get_next_line(int fd)
{
	char	line[(int)1e6] = {};
	char	c;
	int		bytes;
	int		i;

	bytes = 1;
	i = 0;
	while (bytes)
	{
		bytes = read(fd, &c, 1);
		if (bytes < 1)
			break ;
		line[i++] = c;
		if (c == 10)
			break ;
	}
	if (!line[0])
		return (NULL);
	return (stos(line));
}

char	*stos(char *s)
{
	char	*d;
	char	*p;
	int		i;

	i = 0;
	while (s[i])
		++i;
	d = malloc(i + 1);
	p = d;
	while (*s)
		*d++ = *s++;
	*d = 0;
	return (p);
}

*/

//	DRIVE

/*

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

*/
