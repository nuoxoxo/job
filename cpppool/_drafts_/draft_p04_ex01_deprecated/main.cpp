#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static void	print_ending(void) {std::cout << LOWKEY nl "(...end test)" nl2 REST;};

int main()
{
	unsigned int	microsecond = (unsigned int) 1e5;

	// subject
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();	
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		delete j; // should not leak
		delete i;
	}
	
	print_ending();
	
	// some tests
	{
		// usleep(6 * microsecond); // uncomt to make srand useful
		
	}
	
	print_ending();
	
	// more tests . testing srand w/ usleep
	{
		// usleep(6 * microsecond);
	}
	
	print_ending();
	
	// subject
	{
	}
	
	print_ending();

	(void) microsecond;
	std::cout << "do valgrind. " nl2;
}
