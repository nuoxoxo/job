#include"stdarg.h"
#include"stdlib.h"
#include"unistd.h"
#define U unsigned int
int F(va_list, const char);int RS(char*);int Rchr(int);int RD(int);int CD(int);char*SS(char*);char*itoa(int a);int Ruin(U);int Cuin(U);char*uitoa(U);int RH(U,char*);int CH(U);void PH(U,char*);int Rptr(uintptr_t);int Cptr(uintptr_t);void Pptr(uintptr_t);int len(char*);
int ft_printf(const char*s,...){int R=0,i=-1;va_list ap;va_start(ap,s);while(s[++i]){if(s[i]==37){R+=F(ap,s[i+1]);i+=1;}else{R+=1;write(1,&s[i],1);}}return R;}
int F(va_list ap,const char c){int i;if(c=='c'){i=Rchr(va_arg(ap,int));}if(c=='s'){i=RS(va_arg(ap,char*));}if(c=='p'){i = Rptr(va_arg(ap, uintptr_t));}if(c=='d'||c=='i'){i=RD(va_arg(ap,int));}if(c=='u'){i=Ruin(va_arg(ap,U));}if(c=='x'){i=RH(va_arg(ap,U),"0123456789abcdef");}if(c=='X'){i=RH(va_arg(ap,U),"0123456789ABCDEF");}if(c=='%'){i=write(1,&c,1);}return i;}
int Rptr(uintptr_t n){write(1,"0x",2);if(!n)write(1, "0", 1);else Pptr(n);return (Cptr(n));}
void Pptr(uintptr_t n){char*B="0123456789abcdef";if(n>=16)Pptr(n/16);write(1,&B[n%16],1);}
int Cptr(uintptr_t x){int i=3;if(!x)return (i);while(x>=16)x/=16,++i;return i;}
int Rchr(int c){return write(1,&c,1);}
void PH(U n,char*b){if(n>=16)PH(n/16,b);write(1,&b[n%16],1);}
int CH(U x){int i=1;while(x>=16){x/=16;++i;}return i;}
int RH(U n,char*b){PH(n,b);return CH(n);}
char*itoa(int n){int i=CD(n);if(n==-2147483648)return SS("-2147483648");if(!n)return SS("0");char*R=malloc(i+1);if(n<0){n*=-1;R[0]='-';}R[i--]=0;while(n)R[i--]=n%10+'0',n/=10;return R;}
char*SS(char*s){int i=len(s);char*d=malloc(i+1);char*p=d;while(*s)*d++=*s++;*d=0;return p;}
int CD(int n){int i=1;if(n<0)n*=-1;++i;while(n>=10)n/=10;++i;return i;}
int RD(int n){char*S=itoa(n);int i=RS(S);free(S);return i;}
int Ruin(U n){char*S=uitoa(n);int i=RS(S);free(S);return i;}
int Cuin(U n){int i=1;while(n>=10)n/=10,++i;return i;}
char *uitoa(U n){if(!n)return SS("0");int i=Cuin(n);char*R=malloc(i+1);R[i--]=0;while(n)R[i--]=n%10+'0';n/=10;return R;}
int RS(char*s){int i=6;if(!s){write(1,"(null)",i);return i;}i=-1;while(s[++i]){write(1,&s[i],1);}return i;}
int len(char*s){int i=0;while(s[i])++i;return i;}
#include "stdio.h"
#define ss printf("--\n");
int	main()
{
	int n1 = ft_printf(" %s ", "hello, world!");
	printf("\n%i\n", n1);
	ss;
	int n2 = ft_printf(" %d ", -2147483648);
	printf("\n%i\n", n2);
	ss;
	int nd = ft_printf(" %d ", -42);
	printf("\n%i\n", nd);
	ss;
	int n3 = ft_printf(" %x ", 42);
	printf("\n%i\n", n3);
	ss;
	int n4 = ft_printf(" %p ", 0);
	printf("\n%i\n", n4);
	ss;
	int n5 = ft_printf(" %p ", 123);
	printf("\n%i\n", n5);
}
