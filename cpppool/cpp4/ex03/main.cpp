/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                             ~  ~  ~  ~  ~    ~                             */
/*                              ~    _ ~ _   o>                               */
/*                             ~  \ / \ / \ /  ~                              */
/*                              ~  ~      ~    ~                              */
/*                                                                            */
/*                                                                            */
/*                           Abstrac Class (AClass)                           */
/*                             Interface (IClass)                             */
/*                                                                            */
/*                                                                            */
/* *********************  ʕ • ᴥ•ʔ  mode: todo  (⊙. ⊙ )  ********************* */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int	main()
{
	int	i = -1;

	std::cout << GREEN "Test :: " << ++i << " provided by subject";
	std::cout << nl2 RESET;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		
		Character q("q");
		//Character qq(q); // bug in copy
		try
		{
			// std::cout << "@@@\n";
			Character qq(q); // bug in copy
		} catch (const std::exception & e)
		{
			std::cout << e.what() << "\n";
		}

		delete bob;
		delete me;
		delete src;

	}
	std::cout << GREEN "\nTest :: " << ++i << " copy constructor + default Materia";
	std::cout << nl2 RESET;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		// tmp = src->createMateria("cure");
		tmp = src->createMateria("cure (alt.)");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		
		Character q("q");
		//Character qq(q); // bug in copy
		try
		{
			// std::cout << "@@@\n";
			Character qq(q); // bug in copy
		} catch (const std::exception & e)
		{
			std::cout << e.what() << "\n";
		}

		delete bob;
		delete me;
		delete src;

	}

	std::cout << GREEN "\nTest :: " << ++i << " source.learn|create";
	std::cout << nl2 RESET;
	{
		MateriaSource source;
		source.learnMateria(new Ice());
		source.learnMateria(new Cure());

		Character cuckoo("Cuckoo");
		Character brutus("Brutus");
		brutus.equip(source.createMateria("fire"));
		brutus.equip(source.createMateria("ice"));
		brutus.equip(source.createMateria("cure"));
		brutus.use(0, cuckoo);
		brutus.use(1, cuckoo);
		brutus.use(2, cuckoo);
	}
	std::cout << GREEN "\nTest :: " << ++i << " a copied person equips AMT from someone else";
	std::cout << nl2 RESET;
	{
		MateriaSource source;
		source.learnMateria(new Ice());
		source.learnMateria(new Cure());

		Character cuckoo("Cuckoo");
		Character brutus("Brutus");
		brutus.equip(source.createMateria("fire"));
		brutus.equip(source.createMateria("ice"));
		brutus.equip(source.createMateria("cure"));
		// brutus.use(0, cuckoo);
		// brutus.use(1, cuckoo);
		// brutus.use(2, cuckoo);
		
		Character brutus2(brutus);
		
		// BUG here
		//brutus2.equip(brutus.getMateria(0));
		try { brutus2.equip(brutus.getMateria(0)); }
		catch ( const std::exception & e )
		{
			std::cout << e.what() << "\n";
		}
		brutus.unequip(1);
		brutus2.use(0, cuckoo);
		brutus2.use(1, cuckoo);
		brutus2.use(2, cuckoo);
		brutus = brutus2;
	}
}
