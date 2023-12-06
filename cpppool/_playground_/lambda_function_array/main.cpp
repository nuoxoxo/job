#include "iostream"
using	namespace std;

void	op1(int& n) {++n;}
void	op2(int& n) {n += 2;}
void	op3(int& n) {n += 3;}

int	main()
{
	void (*op[]) (int &) = {& op1, & op2, & op3};
	int n = 1024;
	int i = -1;
	while (++i < 3)	op[i](n);
	cout << n << endl;
}
