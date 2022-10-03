#include"stdlib.h"
#include"unistd.h"
char*F(char*s){int i=0;while(s[i])i++;char*d=malloc(i+1),*p=d;while(*s)*d++=*s++;*d=0;return p;}
char*get_next_line(int f){int b=1,i=0;char L[(int)1e6]={},c;while(b){b=read(f,&c,1);if(b<1)break;L[i++]=c;if(c==10)break;}if(!L[0])return NULL;return F(L);}
