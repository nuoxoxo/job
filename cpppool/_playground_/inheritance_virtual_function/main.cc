#include "iostream"
#define	nl "\n"
#define	nll "\n\n"
#define green	"\033[0;32m"
#define yello	"\033[0;33m"
#define reset	"\033[0;0m"
#define endtest ":::::::::::: end test :::::::::::: \n\n"

using	namespace std;

/*** below: class E ***/

class	E
{

protected:
	string	m_name;

public:
	E();
	~E();
	
	float	X, Y;
	
	void	move(float dx, float dy)
	{
		X += dx, Y += dy;
		cout << yello "(moved " << dx << ", " << dy << ") " nl;
	}

	virtual void	show()
	{
		cout << green << "x: " reset << X << nl
		<< green << "y: " reset << Y << nl
		<< "- " << m_name << nll;
	}
};

E::E() : m_name("(an entity)"), X(0.0f), Y(0.0f) {}
E::~E() {}

/*** above: class E ***/
/*** below: class Player ***/

class	Player : public E
{

private:
	string	m_name;

public:
	Player();
	Player(const string &);
	~Player();
	
	void	show()
	{
		cout << green << "x: " reset << X << nl
		<< green << "y: " reset << Y << nl
		<< "- " << m_name << nll;
	}
};

Player::Player() : E(), m_name("i am a player") {}
Player::Player(const string & n) : E(), m_name(n) {}
Player::~Player() {}

/*** above: class E ***/
/*** below: class Player ***/

int	main()
{
	{
		E	entity;

		entity.show();
		entity.move(16.32f, 42.42f);
		entity.move(16.32f + 0.36f, 42.42f + 0.16f);
		entity.show();
	}
	cout << endtest;
	{
		Player	player;

		player.show();
		player.move(16.32f, 42.42f);
		player.move(16.32f + 0.36f, 42.42f + 0.16f);
		player.show();
	}
	cout << endtest;
	{
		Player	*player = new Player("Dave");

		player->show();
		player->move(16.32f, 42.42f);
		player->move(16.32f + 0.36f, 42.42f + 0.16f);
		player->show();
	}
	cout << endtest;
}
