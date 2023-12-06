#include "iostream"
#define	nl "\n"
#define	nll "\n\n"
# define green	"\033[0;32m"
# define yello	"\033[0;33m"
# define reset	"\033[0;0m"
using	namespace std;

/*** below: class E ***/

class	E
{
public:
	E();
	~E();
	float	X, Y;
	void	move(float dx, float dy) {
		X += dx, Y += dy;
		cout << yello "(moved " << dx << ", " << dy << ") " nll;
	}
};

E::E() : X(0.0f), Y(0.0f) {}
E::~E() {}

/*** above: class E ***/
/*** below: class Player ***/

class	Player : public E
{
public:
	Player();
	~Player();
	void	show() {
		cout << green << "x: " reset << X << nl 
		<< green << "y: " reset << Y << nll;
	}
};

Player::Player() : E() {}
Player::~Player() {}

/*** above: class E ***/
/*** below: class Player ***/

int	main()
{
	Player	player;

	player.show();
	player.move(16.32f, 42.42f);
	player.show();
	player.move(16.32f + 0.36f, 42.42f + 0.16f);
	player.show();

}
