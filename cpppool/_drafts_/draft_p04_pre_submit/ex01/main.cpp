#include "cassert"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "Brain.hpp" // added brain
#include "_Cpp04_.hpp"

int	main()
{
	srand(time(0));

	// main provided
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
		// ...
		// return 0;
	}

	print_ending();

	// subject test (filling an array of Animal(s))
	{
		Animal	*gang[B_SIZE];
		int		i;
		int		num_cats, num_dogs, num_other;
		
		i = -1;
		while (++i < B_SIZE)
		{
			if (i < B_SIZE / 2)
			{
				gang[i] = new Cat();
			}
			else
			{
				gang[i] = new Dog();
			}
		}
		
		// counting total creations 
		i = -1;
		num_other = 0;
		num_dogs = num_cats = 0;
		while (++i < B_SIZE)
		{
			if (gang[i]->getType() == "(a cat)")
			{
				++num_cats;
			}
			else if (gang[i]->getType() == "(a dog)")
			{
				++num_dogs;
			}
			else
			{
				++num_other;
			}
		}

		
		
		// destroy
		i = -1;
		while (++i < B_SIZE)
		{
			delete gang[i];
		}
		
		// checking total cats, dogs & non-animals
		assert(num_cats == B_SIZE / 2);
		assert(num_dogs == B_SIZE / 2);
		assert(! num_other);

		std::cout << YELL "total cats: " REST << num_cats << nl;
		std::cout << YELL "total dogs: " REST << num_cats << nl;
		std::cout << YELL "!cats/dogs: " REST
		<< num_other << nl;
		
		
	}

	print_ending();
	
	// more tests . check idea
	
	{
		Dog	*dd = new Dog();

		dd->brain()->makeSound();
		srand(time(0));
		int i = (int) rand() % (B_SIZE + 1);
		dd->brain()->setIdea(i, "zima blue");
		std::cout
		<< dd->getType() << "'s idea at "
		<< i << ": " << dd->brain()->getIdea(i) << nl;

		Dog	ddd(*dd);

		ddd.brain()->makeSound();
		i = (int) rand() % (B_SIZE + 1);
		ddd.brain()->setIdea(i, "4ad");
		std::cout
		<< ddd.getType() << "'s idea at "
		<< i << ": " << ddd.brain()->getIdea(i) << nl;
		i += (int) rand() / 10000 * B_SIZE;
		std::cout
		<< ddd.getType() << "'s idea at "
		<< i << ": " << ddd.brain()->getIdea(i) << nl;

		delete dd;
		// delete ddd;
		// no need to free this dog
	}
	
	print_ending();

}
