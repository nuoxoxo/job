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
/*                                  Casting                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* *********************  ʕ • ᴥ•ʔ  mode: todo  (⊙. ⊙ )  ********************* */

#include "Scalar.hpp"

int	main(int c, char **v)
{
	if (c ^ 2)
		return (_usage_(), 1);

	// std::cout << strIsDigit(std::string(v[1])) << std::endl;
	// std::cout << strIsChar(std::string(v[1])) << std::endl;

	Brain(v[1]);

	(void) c, (void) v;
}
