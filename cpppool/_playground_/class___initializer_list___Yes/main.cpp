#include "iostream"
#include "string"

class	Human
{
private:
	std::string	m_name;
public:
	Human()
		: m_name("(none)")
	{}

	/*
	Human()
	{
		m_name = "(none)";
	}
	*/

	Human( const std::string & name )
		: m_name(name)
	{}

	/*
	Human( const std::string & name )
	{
		m_name = name;
	}
	*/
	
	virtual ~Human()
	{
	}

	const std::string & GetName() const
	{
		return m_name;
	}
};

int	main()
{
	Human	human_0;
	Human	human_1("Johnny");

	std::cout << human_0.GetName() << std::endl;
	std::cout << human_1.GetName() << std::endl;
}
