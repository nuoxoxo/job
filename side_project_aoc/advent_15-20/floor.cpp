#include "iostream"

int	main()
{
	int		count;
	int		posit;
	int		i;
	char	c;

	count = 0;
	posit = 0;
	i = 0;
	while (std::cin >> c)
	{
		posit = count == -1 && !posit ? i : posit;
		count = c == '(' ? count + 1 : count - 1;
		i++;
	}
	std::cout << "Star 1 : " << count << '\n' 
	std::cout << "Star 2 : " << posit << '\n';
}
