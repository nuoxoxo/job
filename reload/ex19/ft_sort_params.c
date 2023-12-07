/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:11:17 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/18 15:02:21 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// DRIVE

void    sort_args(int hello, char **world);
void    ft_psnl(char *hello);
int     ft_strcmp(char *hello, char *world);

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		sort_args(argc, argv);
		i = 1;
		while (i < argc)
			ft_psnl(argv[i++]);
	}
	return (0);
}

//

void	sort_args(int argc, char **argv)
{
	char    *tmp;
	int     counter;
	int     i;

	counter = -1;
	while (counter != 0)
	{
		i = 1;
		counter = 0;
		while (i < argc - 1)
		{	
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				counter++;
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
			}
			i++;
		}
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
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
