/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:54:55 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/23 17:36:10 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*

//  DRIVE

#include <stdio.h>

int     *ft_range(int petit, int grand);

int     main()
{
	int min = 42;
	int max = 46;
	int i = 0;
	int *p = ft_range(min, max);
	while (i < max - min)
		printf("%i ", p[i++]);
}

*/

int	*ft_range(int min, int max)
{
	int	diff;
	int	*ptr;
	int	i;

	diff = max - min;
	if (diff <= 0)
		return (NULL);
	ptr = malloc(sizeof(int) * diff);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < diff)
		ptr[i++] = min++;
	return (ptr);
}
