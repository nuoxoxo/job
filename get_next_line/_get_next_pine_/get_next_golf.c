#include "stdlib.h"
#include "unistd.h"
char *ss(char *s){
    int i=0;
    while (s[i]) i++;
    char *d=malloc(i+1), *p = d;
    while (*s) *d++=*s++;
    *d=0;
    return p ;
}
char *get_next_line(int fd){
    char L[(int)1e6]={}, c;
    int B=1,i=0;
    while(B){
        if((B = read(fd, &c, 1)) < 1) break ;
        L[i++] = c; if(c == 10) break ;
    }
    if(!L[0]) return 0 ;
    return ss(L) ;
}
