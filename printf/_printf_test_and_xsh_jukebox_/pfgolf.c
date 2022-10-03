#include"stdarg.h"
#include"stdlib.h"
#include"unistd.h"
#define U unsigned int
#define up uintptr_t
#define rt return
#define G va_arg
#define w while
#define W write
#define C char
#define I int
I F(va_list, const C);I RS(C*);I Rc(I);I D(I);I CD(I);C*SS(C*);C*It(I a);I Ru(U);I Cu(U);C*Ut(U);I H(U,C*);I CH(U);void PH(U,C*);I Rp(up);I Cp(up);void Pp(up);I L(C*);I ft_printf(const C*s,...){I R=0,i=-1;va_list a;va_start(a,s);w(s[++i]){if(s[i]==37)R+=F(a,s[++i]);else{++R;W(1,&s[i],1);}}rt R;}I F(va_list a,const C c){I i;if(c==99){i=Rc(G(a,I));}if(c=='s'){i=RS(G(a,C*));}if(c=='p'){i=Rp(G(a, up));}if(c=='d'||c=='i'){i=D(G(a,I));}if(c==117){i=Ru(G(a,U));}if(c=='x'){i=H(G(a,U),"0123456789abcdef");}if(c==88){i=H(G(a,U),"0123456789ABCDEF");}if(c==37){i=W(1,&c,1);}rt i;}I Rp(up n){W(1,"0x",2);if(!n)W(1,"0",1);else Pp(n);rt Cp(n);}void Pp(up n){C*B="0123456789abcdef";if(n>15)Pp(n/16);W(1,&B[n%16],1);}I Cp(up x){I i=3;if(!x)rt i;w(x>15)x/=16,++i;rt i;}I Rc(I c){rt W(1,&c,1);}void PH(U n,C*b){if(n>15)PH(n/16,b);W(1,&b[n%16],1);}I CH(U x){I i=1;w(x>15){x/=16;++i;}rt i;}I H(U n,C*b){PH(n,b);rt CH(n);}C*It(I n){I i=CD(n);if(n==-2147483648)rt SS("-2147483648");if(!n)rt SS("0");C*R=malloc(i+1);if(n<0){n=-n;R[0]='-';}R[i--]=0;w(n)R[i--]=n%10+'0',n/=10;rt R;}C*SS(C*s){I i=L(s);C*d=malloc(i+1);C*p=d;w(*s)*d++=*s++;*d=0;rt p;}I CD(I n){I i=1;if(n<0)n=-n,++i;w(n>9)n/=10,++i;rt i;}I D(I n){C*S=It(n);I i=RS(S);free(S);rt i;}I Ru(U n){C*S=Ut(n);I i=RS(S);free(S);rt i;}I Cu(U n){I i=1;w(n>9)n/=10,++i;rt i;}C*Ut(U n){if(!n)rt SS("0");I i=Cu(n);C*R=malloc(i+1);R[i--]=0;w(n)R[i--]=n%10+'0',n/=10;rt R;}I RS(C*s){I i=6;if(!s){W(1,"(null)",i);rt i;}i=-1;w(s[++i]){W(1,&s[i],1);}rt i;}I L(C*s){I i=0;w(s[i])++i;rt i;}
