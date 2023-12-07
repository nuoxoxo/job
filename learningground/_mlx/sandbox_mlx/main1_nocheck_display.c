/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nxu              ...   ::::::::.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "stdlib.h"

int	main(void)
{
	void	*ptr;

	ptr = mlx_init();
	mlx_destroy_display(ptr);
	free(ptr);
}

/* OSX:	mlx_destroy display not working	*/
