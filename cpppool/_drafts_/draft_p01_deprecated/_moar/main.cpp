# include "iostream"
# include "string"
# include "zombie_color.hpp"

using namespace	std;

/*		class		*/


class	Zombie
{
	private:
		string		name;
		void		label(void) const;

	public:
		Zombie(void);
		//~Zombie(void);
		virtual		~Zombie(void);
		void		set_name(string); // can't be const
		void		announce(void) const;
		string		get_name(void) const;
};


/*		prototype		*/


Zombie		*create_zombie_horde(int, string);
void		announce_foreach(int, Zombie *);


/*		drive		*/


int	main(const int c, const char **v)
{
	Zombie			*flock;
	string		arg1;
	string		name;
	int			numb;

	if (c > 1)
		arg1 = string(v[1]);
	numb = 42;
	name = "";
	if (c == 2)
	{
		if (isdigit(v[1][0]))
			numb = stoi(arg1);
		else
			name = arg1;

	}
	else if (c > 2)
	{
		if (isdigit(v[1][0]))
			numb = stoi(arg1);
		name = string(v[2]);
	}

	//cout << numb << '\n' << name << endl; // debugger

	flock = create_zombie_horde(numb, name);
	announce_foreach(numb, flock);
	delete [] flock;
}


/*		member functions		*/


Zombie::Zombie(void) : name("")
{}


Zombie::~Zombie(void) {
	Zombie::label();
	cout << _cyan "is destroyed. \n" _reset;
}



string	Zombie::get_name(void) const
{ return (this->name); }


void	Zombie::label(void) const
{ cout << _green "﹤" << this->name << "﹥" _reset; }


void	Zombie::set_name(string name) {
	if (name == "")
		this->name = "T-1000";
	else
		this->name = name;
}


void	Zombie::announce(void) const {
	Zombie::label();
	cout << "BraiiiiiiinnnzzzZ... \n";
}


/*		non-member function		*/


Zombie	*create_zombie_horde(int N, string name)
{
	int		i;
	Zombie		*zh = new Zombie[N];

	i = -1;
	while (++i < N)
	{
		zh[i].set_name(name);
	}
	return (zh);
}


void	announce_foreach(int N, Zombie *zh)
{
	int		i;

	i = -1;
	while (++i < N)
	{
		cout << _yellow "zombie no." _reset << 1 + i << ' ';
		zh[i].announce();
	}
}
