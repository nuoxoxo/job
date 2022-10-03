/* ******************************************** */
/*                                              */
/*              ~  ~  ~  ~  ~    ~              */
/*               ~    _ ~ _   o>                */
/*              ~  \ / \ / \ /  ~               */
/*               ~  ~      ~    ~               */
/*                                              */
/* ******************************************** */

#include "iostream"
#include "fcntl.h"
#include "unistd.h"

#ifndef BU
#define BU 32
#endif
#define ss printf("---\n")

using   namespace std;
using   cs = char *;

cs      get_chunk(int, cs &);
cs      get_words(cs&);
cs      new_chunk(cs&);
cs      G(int, cs&);
cs      C(int, cs);
cs      J(cs, cs);
int     L(cs);

char    *G(int f, cs& chunk)
{
        cs  words;

        if (f < 0 || BU < 1) return 0 ;
        chunk = get_chunk(f, chunk);
        if (!chunk) return NULL ;
        words = get_words(chunk);
        chunk = new_chunk(chunk);
        return words ;
}

char    *get_chunk(int f, cs &chunk)
{
        cs  buff;
        int bytes;

        buff = (cs) malloc(sizeof(char)*(BU + 1));
        bytes = 1;
        while (!C(10, chunk) && bytes)
        {
            bytes = read(f, buff, BU);
            if (bytes == -1) return NULL ;
            buff[bytes] = '\0';
            chunk = J(chunk, buff);
        }

        return chunk ;
}

char    *get_words(cs& chunk)
{
        cs  words;
        int i;

        i = 0;
        if (!chunk[i])  return NULL ;
        while (chunk[i] && chunk[i] != 10)  i++ ;
        words = (cs) malloc(sizeof(char) * (i + 2));
        i = -1;
        while (chunk[++i] && chunk[i] != 10) words[i] = chunk[i];
        if (chunk[i] && chunk[i] == 10) words[i] = chunk[i];
        words[++i] = '\0';

        return words ;
}

char    *new_chunk(cs &chunk)
{
        int i = 0, j;
        cs  words;

        while (chunk[i] && chunk[i] != 10) i++ ;
        if (!chunk[i])  return NULL ;
        words = (cs) malloc(sizeof(char) * (L(chunk) - i + 1));
        i++ ;
        j = 0;
        while (chunk[i]) words[j++] = chunk[i++];
        words[j] = '\0';
        return words ;
}

char	*J(cs chunk, cs buff)
{
	cs  rest;
	int size, i = -1, j = 0;

        if (!chunk)
        {
            chunk = (cs) malloc(sizeof(char));
            chunk[0] = '\0';
        }
	size = L(chunk) + L(buff) + 1;
	rest = (cs) malloc(sizeof(char) * size);
	while(chunk[++i])   rest[i] = chunk[i];
	while(buff[j])      rest[i++] = buff[j++];
	rest[size - 1] = 0;

	return rest ;
}

char	*C(int c, cs s)
{
	int i = -1;
	if (!s) return 0 ;
	while(s[++i])
            if (s[i] == c)  return ((cs) &s[i]) ;
	if (!c)
            return ((cs) &s[i]) ;

        return 0 ;
}

int	L(cs s)
{
	int i = 0;
	if (!s)	return i ;
	while(s[i]) i++ ;

        return i ;
}

int	main(int argc, cs argv[])
{
	cs  chunk;
        cs  words;
	int fd, i = 0;
        int T = (argc == 1) ? 0 : atoi(argv[1]);
        int L = (argc == 3) ? atoi(argv[2]) : 16;

        T = T < 7 ? T : 1;
        if (!T) L = 8;
        if (argc == 2) {
            if (T == 3) L = 42;
            if (T == 6) L = 42;
            if (T == 0) L = 8;
            if (T == 2) L = 10;
            if (T == 4) L = 128;
            if (T == 5) L = 512;
        }
        if (T == 1) fd = open("texts/MSP", O_RDONLY);
	if (T == 2) fd = open("texts/RT", O_RDONLY);
        if (T == 3) fd = open("texts/JG", O_RDONLY);
	if (T == 4) fd = open("texts/AOC", O_RDONLY);
	if (T == 5) fd = open("texts/AOC5", O_RDONLY);
	if (T == 6) fd = open("texts/HEAD", O_RDONLY);
	if (T == 0) fd = open("texts/ANM", O_RDONLY);
	if (T == 0) fd = open("texts/ANM", O_RDONLY);
        ss;
        while( ++i < L + 1 ) {
            words = G(fd, chunk);
            printf("# %02d: %s", i, words);  /// display #1

            /*cout << "# ";                 /// display #2 - segfault if !words
            if (i < 10) cout << '0';
            cout << i << ": " << words;
            */

            if (!words)
                cout << '\n';
            else
                free(words);
        }
        ss;
        close(fd);

        return 0;
}

