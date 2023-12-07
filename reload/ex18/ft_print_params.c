/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 09:59:19 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/18 14:58:17 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_psnl(char *world);

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
			ft_psnl(argv[i++]);
	}
	return (0);
}

void	ft_psnl(char *s)
{
	
        if (s)
        {
            while (*s)
		write(1, s++, 1);
	}
	write(1, "\n", 1);
}
