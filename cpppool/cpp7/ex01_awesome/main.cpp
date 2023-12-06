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
/*                                                                            */
/*                                 Template                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* *********************  ʕ • ᴥ•ʔ  mode: todo  (⊙. ⊙ )  ********************* */

#include "iter.hpp"
#include "iomanip"
#include "Awesome.hpp"

int	main()
{		
		int	tab[] = {0, 1, 2, 3, 4}; // <--- ....

		Awesome	tab2[5];

		iter(tab, 5, print<int>);
		iter(tab2, 5, print<Awesome>);

		std::cout << std::endl;
}

