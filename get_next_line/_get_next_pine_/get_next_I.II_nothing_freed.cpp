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
#define SEP printf("--\n")
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif

using   namespace std;
char    *get_chunk(int, char *&);
char    *get_words(char *&);
char    *new_words(char *&);
char    *gnl(int, char *&);
char    *SJ(char *, char *);
char    *SC(char *, int);
size_t  len(char *);

char    *gnl(int f, char *& chunk) // chunk pre-defined in main
{
        char *words;
        if (f < 0 || BUFFER_SIZE < 1)   return 0 ;
        chunk = get_chunk(f, chunk);
        if (!chunk) return NULL ;
        words = get_words(chunk);
        chunk = new_words(chunk);
        return words ;
}

char    *get_chunk(int f, char *& chunk)
{
        char *buff;
        int bytes;
        buff = (char *)malloc(sizeof(char)*(BUFFER_SIZE+1));
        bytes = 1;
        while(!SC(chunk, 10) && bytes)
        {
            bytes = read(f,buff,BUFFER_SIZE);
            if (bytes == -1)    return NULL ;
            buff[bytes] = '\0';
            chunk = SJ(chunk, buff);
        }
        // no need to free anything
        return chunk ;
}

char    *get_words(char *& chunk)
{
        char *words;
        int i;

        i = 0;
        if (!chunk[i])   return NULL ;
        while(chunk[i] && chunk[i]!=10)  i ++;
        words = (char*)malloc(sizeof(char)*(i+2));

        i = -1;
        while(chunk[++i] && chunk[i]!=10)    words[i] = chunk[i];
        if (chunk[i] && chunk[i]==10) words[i] = chunk[i];
        words[++i] = '\0';

        return words ;
}

char    *new_words(char *&chunk)
{
        char *words;
        int i, j;
        i = 0;
        while(chunk[i] && chunk[i]!=10)  i ++;
        if (!chunk[i])  return NULL ;
        words = (char*)malloc(sizeof(char)*(len(chunk) - i + 1));

        i ++ ; j = 0;
        while(chunk[i]) words[j ++] = chunk[i ++];
        words[j] = '\0';
        return words ; // no need to free chunk
}

//      Drive at the end
//      Drive at the end
//      Drive at the end
//      Drive at the end
//      Drive at the end
//      Drive at the end
//      Drive at the end
//      Drive at the end
//      Drive at the end
//      Drive at the end
//      Drive at the end

int	main(int argc, char *argv[])
{
	char *chunk;
        char *words;
	int  fd, i = 0;

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
        SEP;
        while( ++i < L + 1 ) {
            words = gnl(fd, chunk);
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
        SEP;
        close(fd);

        return 0;
}

//      SC . SJ . len
//      SJ . len . SC
//      len . SJ . SC
//      SC . SJ . len
//      SJ . len . SC
//      len . SJ . SC
//      SC . SJ . len
//      SJ . len . SC
//      len . SJ . SC
//      SC . SJ . len
//      SJ . len . SC
//      len . SJ . SC
//      SC . SJ . len
//      SJ . len . SC
//      len . SJ . SC
//      SC . SJ . len
//      SJ . len . SC
//      len . SJ . SC

char	*SJ(char *chunk, char *buff)
{
	char *rest;
	int  size, i = -1, j = 0;
	if (!chunk)
        {
            chunk=(char*)malloc(sizeof(char));
            chunk[0] = '\0';
        }
	size = len(chunk) + len(buff) + 1;
	rest = (char*)malloc(sizeof(char)*size);
	while(chunk[++ i])  rest[i] = chunk[i];
	while(buff[j])      rest[i++] = buff[j++];
	rest[size-1] = 0;

	return rest ;
}

char	*SC(char *s, int c)
{
	int i = -1;
	if (!s) return 0 ;
	while(s[++i])
            if (s[i] == c)  return ((char*) &s[i]) ;
	if (!c)
            return ((char*) &s[i]) ;

        return 0 ;
}

size_t	len(char *s)
{
	int i = 0;
	if (!s)	return i ;
	while(s[i]) i++ ;

        return i ;
}
