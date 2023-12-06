#include "iostream"
#define	called " called. \n"

using namespace std;

class	Head
{
	public:
		Head()		{ cout << __FUNCTION__ << called; }
		~Head()		{ cout << __FUNCTION__ << called; }
};

class	Dummy:	public	Head
{
	public:
		Dummy()		{ cout << __FUNCTION__ << called; }
		~Dummy()	{ cout << __FUNCTION__ << called; }
};

//	Drive

int	main()
{
	Dummy	*dumm = new Dummy();
	Head	*head = dumm;
	delete	head;
//	getchar();
}
