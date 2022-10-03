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

//#include "get_next_line.h"
#include "get_next_jan06.h"
//#include "unistd.h"
//#include <stdlib.h>

//#ifndef	BUFFER_SIZE
//#define	BUFFER_SIZE 32
//#endif

//char	*get_next_line(int);
//char	*get_bloc(int, char *);
//char	*get_line(char *);
//char	*new_bloc(char *);
//char	*gen_bloc(char *, char *); // ---> char	*sj(char *, char *);
//char	*sc(int, char *);
//int	len(char *);

char	*get_next_line(int f)
{
	static char	*bloc;	// statics are always zero-initialised before
				// any other initialisation is performed
	char		*line;

	if (f < 0 || BUFFER_SIZE < 1)	// negative file descriptor OR no buff size
		return (NULL);		// both 0 and NULL work fine
	bloc = get_bloc(f, bloc);	// get bloc (use fd to get bloc)
	if (!bloc)
		return (NULL);		// (check bloc)
	line = get_line(bloc);		// get line
	bloc = new_bloc(bloc);		// new bloc
	return (line);			// (always return a nl-ended line)
}

char	*gen_bloc(char *L, char *R)	// strjoin modified
{
	char	*res;
	int		i;
	int		j;
	int		size;

	if (!L)						// if no L (1st check)
	{
		L = (char *) malloc(sizeof(char));	// 1) malloc size of 1
		L[0] = 0;				// 2) its only char \0
	}
	if (!L || !R)			// if no L (malloc fail) or no bloc
		return (NULL);
	size = len(L) + len(R);		// prepare enough length of bloc (L(bloc)+L(buff))
	res = (char *) malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (L[++i])
		res[i] = L[i];		// cpy original L to result str
	j = 0;
	while (R[j])
		res[i++] = R[j++];	// cat buff to result str
	res[size] = 0;			// seal result str
	free(L);// added line		// FREE bloc
	return (res);
}

char	*get_bloc(int f, char *bloc)	// you have a static bloc, append it with what u read
{
	char	*buff;			// our temp buffer (fill it, empty it, fill again ...)
	int		bytes;		// bytes read to keep track of how much you read

	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));	// init buff size+1
	if (!buff)
		return (NULL);
	bytes = 1;					// init the number of bytes seen
	while (bytes && !sc(10, bloc))			// go on reading until a \n appears
	{
		bytes = read(f, buff, BUFFER_SIZE);	// read it - format : (fd, buf, BSZ)
		if (bytes == -1)			// bytes read if -1 : error
		{
			free(buff);// added line	// on error, free the malloc-ed buffer
			return (NULL);
		}				// if success, buffer is filled
		buff[bytes] = '\0';		// on success, seal buff with 0
		bloc = gen_bloc(bloc, buff);	// append filled buffer to the staic bloc
	}
	free(buff);// added line		// free the buff
	return (bloc);				// return the static bloc
}

char	*get_line(char *bloc)	// extract a line outta the bloc
{
	char	*line;
	int		i;

	i = 0;
	if (!bloc[i])			// out static bloc enters the 2nd fn, check its [0]
		return (NULL);
	while (bloc[i] && bloc[i] != 10)		// get to the first newline or NUL
		i ++;
	line = (char *) malloc(sizeof(char) * (i + 2));	// malloc the line size + 2
	if (!line)
		return (NULL);
	i = -1;
	while (bloc[++i] && bloc[i] != 10)		// copy to line until end (\0 or \n)
		line[i] = bloc[i];
	if (bloc[i] && bloc[i] == 10)			// now if the last [i] is \n, copy it
		line[i] = bloc[i];
	line[++i] = '\0';				// seal the line
	return (line);					// deliver it
}

char	*new_bloc(char *bloc)	// create a substr of the bloc, it becomes the bloc
{
	char	*line;
	int		size;
	int		i;
	int		j;

	i = 0;
	while (bloc[i] && bloc[i] != 10)		// get to the first newline or NUL
		i ++;
	if (!bloc[i])					// if it is a NUL, it means Game Over:
	{
		free(bloc);// added line		// 1) free the bloc
		return (NULL);				// 2) get outta here
	}						// if it is NOT a NUL, its a \n

	size = len(bloc) - i;				// len_rest = len_bloc - len_1st_line
	line = (char *)malloc(sizeof(char)*(size + 1));	// malloc the line
	if (!line)
		return (NULL);
	i ++;						// move pointer to [ newline + 1 ]
	j = 0;
	while (bloc[i])
		line[j++] = bloc[i++];			// create a substr of rest of the bloc
	line[j] = '\0';					// seal it

	free(bloc);// added line			// IMPORTANT: free the bloc before we leave
	return (line);					// deliver it
}


#include "fcntl.h"
#include "stdio.h"
#define ss printf("---\n")

int	main(int argc, char *argv[])
{
        char	*line;
	int f, i = 0;
        int T = (argc == 1) ? 0 : atoi(argv[1]);
        int L = (argc == 3) ? atoi(argv[2]) : 16;

        //T = T < 7 ? T : 1;
	T = T < 8 ? T : 1;	// Added NO_NL test which contains one only line of digits - arg2 : 7
	if (!T) L = 8;
        if (argc == 2) {
            if (T == 3) L = 42;
            if (T == 6) L = 42;
            if (T == 0) L = 8;
            if (T == 2) L = 10;
            if (T == 4) L = 128;
            if (T == 5) L = 512;
	    if (T == 7)	L = 4;				// Added NO_NL 
        }
        if (T == 1) f = open("texts/MSP", O_RDONLY);
	if (T == 2) f = open("texts/RT", O_RDONLY);
        if (T == 3) f = open("texts/JG", O_RDONLY);
	if (T == 4) f = open("texts/AOC", O_RDONLY);
	if (T == 5) f = open("texts/AOC5", O_RDONLY);
	if (T == 6) f = open("texts/HEAD", O_RDONLY);
	if (T == 0) f = open("texts/ANM", O_RDONLY);
	if (T == 0) f = open("texts/ANM", O_RDONLY);
	if (T == 7) f = open("texts/NO_NL", O_RDONLY); // Added NO_NL

	ss;
        while( ++i < L + 1 ) {
            line = get_next_line(f);
            printf("# %02d: %s", i, line);  /// display #1

            //cout << "# ";                 /// display #2 - segfault if !line
            //if (i < 10) cout << '0';
            //cout << i << ": " << line;

            if (!line)
                printf("\n");
            else
                free(line);
        }
        ss;
        close(f);
        return 0;
}
