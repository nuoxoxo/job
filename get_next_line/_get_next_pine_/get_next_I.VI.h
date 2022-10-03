/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ____/__/__ __:__:__ by nuo               #+#    #+#             */
/*   Updated: ____/__/__ __:__:__ by nuo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdlib.h"
# include "unistd.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*get_next_line(int x);
char	*get_bloc(int x, char *y);
char	*gen_bloc(char *x, char *y);
char	*get_line(char *x);
char	*new_bloc(char *x);
char	*sc(int x, char *y);
int	len(char *x);

#endif
