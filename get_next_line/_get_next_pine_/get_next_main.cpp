/* ************************************************************************** */
/*                                                                            */
/*                            \\             /`/``                            */
/*                            ~\o o_       0 0\                               */
/*                            / \__)      (u  ); _  _                         */
/*                     / \/ \/  /           \  \/ \/ \                        */
/*                    /(   . . )            (         )\                      */
/*                   /  \_____/              \_______/  \                     */
/*                       []  []               [[] [[]    *.                   */
/*                       []] []]              [[] [[]                         */
/*                                                                            */
/* ****************************************************************** nuo *** */

#include "iostream"
#include "fstream"

int     main(int argc, char **argv)
{
        std::ifstream   fs;
        std::string     s;
        int             i = 0, L, T;

        T = (argc == 1) ? 0 : atoi(argv[1]);
        L = (argc == 3) ? atoi(argv[2]) : 16;
        if (!T) L = 8;
        if (argc == 2) {
            if (T == 3 || T == 6)   L = 42;
            if (T == 0) L = 8;
            if (T == 4) L = 128;
            if (T == 5) L = 512;
        }
        if (T > 6) return (1);
        if (T == 1) fs.open("texts/MSP");
	if (T == 2) fs.open("texts/RT");
	if (T == 3) fs.open("texts/JG");
	if (T == 4) fs.open("texts/AOC");
	if (T == 5) fs.open("texts/AOC5");
	if (T == 6) fs.open("texts/HEAD");
	if (T == 0) fs.open("texts/ANM");

        std::cout << "--\n";
        while (++i < L + 1) {
            getline(fs, s);
            std::cout << "# ";
            if (i < 10) std::cout << "0";
            std::cout << i << ": " << s << "\n";
        }
        std::cout << "--\nFile option: " << T << "\nRows viewed: " << L << "\n";
        if (T == 3) std::cout << "(john giorno's poem, 36+ lines)\n";
        if (T == 4) std::cout << "(long text, ~ 100 lines)\n";
        if (T == 5) std::cout << "(AOC 2021 Day 5 input, ~ 500 rows)\n";
        if (T == 6) std::cout << "(headers, 32+ lines)\n";
        std::cout << "--\n";

        fs.close();

        return (0);
}
