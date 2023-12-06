#include "iostream"

#define ylo "\033[1;33m"
#define cyn "\033[1;36m"
#define noc "\033[0m"
#define grn "\033[1;32m"
#define red "\033[1;31m"
#define wht "\e[0;37m"
#define boi "\033[1m"
#define mgt "\033[0;35m"

class	LOG
{
public:
	enum	LogLevel
	{
		LogLevelZero,
		LogLevelError,
		LogLevelWarning,
		LogLevelInfo,
		LogLevelLast // 
	};
private:

	int	m_LogLevel = LogLevelInfo;

	// "m_" indicates a class member variable that is private

public:
	~LOG()
	{
		std::cout << wht "(";
		std::cout << __PRETTY_FUNCTION__;
		std::cout << " called) \n" noc;
	}

	void	SetLevel(int level)
	{
		if (level < 0 || level >= LogLevelLast)
			return ;
		m_LogLevel = level;
	}

	void	Error(std::string msg)
	{
		if (m_LogLevel < LogLevelError)
			return ;
		std::cout << "[" << ylo " ERROR " noc << "]\t";
		std::cout << msg << std::endl;
	}

	void	Warn(std::string msg)
	{
		if (m_LogLevel < LogLevelWarning)
			return ;
		std::cout << "[" << red " WARNING " noc << "]\t";
		std::cout << msg << std::endl;
	}

	void	Info(std::string msg)
	{
		if (m_LogLevel < LogLevelInfo)
			return ;
		std::cout << "[" << grn " INFO " noc << "]\t";
		std::cout << msg << std::endl;
	}

	void	CurrLevel(void)
	{
		std::cout << "[" << mgt " Level " noc << "]\t";
		std::cout << m_LogLevel << std::endl;
	}

	void	LogAll(std::string msg)
	{
		std::cout << std::endl;

		CurrLevel();
		Info(msg);
		Warn(msg);
		Error(msg);

		std::cout << wht "\n(";
		std::cout << __PRETTY_FUNCTION__;
		std::cout << " called) \n" noc;
	}
};

//	Drive

int	main()
{
	LOG	log;

	log.LogAll("Hello, World!");

	log.SetLevel(log.LogLevelWarning);
	log.LogAll("Hello, World!");

	log.SetLevel(log.LogLevelError);
	log.LogAll("Hello, World!");

	// Try set log level to an impossible

	log.SetLevel(42);
	log.LogAll("Hello, World!");
}
