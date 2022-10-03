/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

#include "unistd.h"
#include "stdarg.h"

int	FMT(va_list, const char c);
int	ps(char *);

int	P(const char *s, ...)
{
	int		plen, i;
	va_list		ap;

	va_start(ap, s);
	i = plen = 0;
	while (s[i])
	{
		if (s[i] == 37)	plen += FMT(ap, s[i + 1]), i++;
		else		plen ++, write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return plen ;
}

int	FMT(va_list ap, const char f)
{
	int	len;

	len = 0;
	if ( f == 's' )	len += ps(va_arg(ap, char *));
	if ( f == '%' )	write(1, "%", 1), len ++;
	return len ;
}

int	ps(char *s)
{
	int	i;

	if (!s) {
		write(1, "(null)", 6);
		return 6 ;
	}
	i = -1;
	while (s[++i])	write(1, &s[i], 1);
	return i ;
}

//	DRIVE

#include "stdio.h"
#define ss write(1,"---\n",4)

int	main()
{
	char *s = 
"Lorem ipsum dolor sit amet, consectetur adipiscing elit, \
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. \
Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris \
nisi ut aliquip ex ea commodo consequat. \
Duis aute irure dolor in reprehenderit in voluptate \
velit esse cillum dolore eu fugiat nulla pariatur. \
Excepteur sint occaecat cupidatat non proident, \
sunt in culpa qui officia deserunt mollit anim id est laborum.";

	write(1,"test s\n---\n",11);
	P("%s\n", "");ss;
	P(" %s\n", "");ss;
	P("%s \n", "");ss;
	P(" %s \n", "");ss;
	P(" %s \n", "-");ss;
	P(" %s %s \n", "", "-");ss;
	P(" %s %s \n", " - ", "");ss;
	P(" %s %s %s %s %s\n", " - ", "", "4", "", s);ss;
	P(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");ss;
}
