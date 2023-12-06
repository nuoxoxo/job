#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include "_Cpp04_.hpp"

int	main()
{
	int		i = 0;

	srand(time(0));

	// subject
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();	
		std::cout << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete i;
		delete j;
	}
	
	print_ending();
	
	// some tests
	{
		Animal	*Jeffe = new Animal();
		Animal	Jorge("Jorge");

		Jeffe->makeSound();
		Jorge.makeSound();
		

		Dog	*Dylan = new Dog();

		Dylan->makeSound();

		/*
		try { Dog Jorge("Jorge"); }
		catch (const std::runtime_error & e)
		{ std::cerr << e.what() << std::endl; }
		*/
		
		Cat	*Cathy = new Cat();
		
		Cathy->makeSound();

		// bye
		delete	Jeffe;
		delete	Cathy;
		delete	Dylan;
	}
	
	print_ending(i++);
	
	// more tests . testing srand w/ usleep
	{
		Animal	*Jeffe = new Animal();
		Animal	Jorge("Jorge");

		Jeffe->makeSound();
		Jorge.makeSound();
		

		Dog		*Dylan = new Dog();		// is a dog on removal of `virtual`
		Animal	*Dylan2 = new Dog();	// is an Animal object on removal of `virtual`
		
		// Dog	*Dylan3 = new Animal(); // mission impossible <- declare in reversed hierarchy

		Dylan->makeSound();
		Dylan2->makeSound();

		// Dylan3->makeSound(); // mission impossible

		/*
		try { Dog Jorge("Jorge"); }
		catch (const std::runtime_error & e) { std::cerr << e.what() << std::endl; }
		*/
		
		Cat	*Cathy = new Cat();
		
		Cathy->makeSound();

		// bye
		delete	Jeffe;
		delete	Cathy;
		delete	Dylan;
	}
	
	print_ending(i++);
	
	// subject
	{
		std::cout
		<< CYAN "retry the subject main w/ WrongClass " nl REST;

		WrongAnimal* meta = new WrongAnimal();
		WrongAnimal* i = new WrongCat();

		// WrongAnimal* wrong_cat = new Cat(); // mission impossible
		
		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		
		i->makeSound(); //will output the cat sound!
		meta->makeSound();
		
		delete meta;
		delete i;
	}
	
	print_ending(i++);

	std::cout << "do valgrind. " nl2;
}
