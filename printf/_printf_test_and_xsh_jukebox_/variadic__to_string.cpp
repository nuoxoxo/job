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

#include "iostream"
#include "sstream"
#define S printf("--\n")

template<typename T>
void    PS(const T& t)		// put string
{
        std::cout << t << '\n';
}

template<typename T>
std::string PSS(const T& t)	// same operation using sstream
{
        std::stringstream   ss;

        ss << t;
        return ss.str() ;
}

int     main()
{
        S;
        PS("Hello, World!");
        PS(1024);
        PS(3.14159);
        S;
        std::cout << PSS("Hello, World!")<<'\n';
        std::cout << PSS(512) << '\n';
        std::cout << PSS(3.14) << '\n';
        S;
}
