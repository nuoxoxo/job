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

#include "get_next_line.h"

/*
char	*get_chunk(int f, char *chunk)
{
	int		bytes;
	char	*buff;

	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes = 1;
	while (!C(10, chunk) && bytes)
	{
		bytes = read(f, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		buff[bytes] = '\0';
		chunk = J(chunk, buff);
	}
	return (chunk);
}

char	*get_words(char *chunk)
{
	char	*words;
	int		i;

	i = 0;
	if (!chunk[i])
		return (NULL);
	while (chunk[i] && chunk[i] != 10)
		i ++;
	words = (char *) malloc(sizeof(char) * (i + 2));
	i = -1;
	while (chunk[++i] && chunk[i] != 10)
		words[i] = chunk[i];
	if (chunk[i] && chunk[i] == 10)
		words[i] = chunk[i];
	words[++i] = '\0';
	return (words);
}

char	*new_chunk(char *chunk)
{
	char	*words;
	int		len;
	int		i;
	int		j;

	i = 0;
	while (chunk[i] && chunk[i] != 10)
		i ++;
	if (!chunk[i])
		return (NULL);
	len = 0;
	while (chunk[len])
		len ++;
	words = (char *) malloc(sizeof(char) * (len - i + 1));
	if (!words)
		return (NULL);
	i ++;
	j = 0;
	while (chunk[i])
		words[j++] = chunk[i++];
	words[j] = '\0';
	return (words);
}
*/

int	sl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*sj(char *chunk, char *buff)
{
	char	*rest;
	int		i;
	int		j;
	int		size;

	//if (!buff)
	//	return (NULL);	// ......
	if (!chunk)
	{
		chunk = (char *) malloc(sizeof(char));
		if (!chunk)
			return (NULL);
		chunk[0] = 0;
	}
	if (!buff)
		return (NULL);
	size = sl(chunk) + sl(buff);
	rest = (char *) malloc(sizeof(char) * (size + 1));
	if (!rest)
		return (NULL);
	i = -1;
	while (chunk[++i])
		rest[i] = chunk[i];
	j = 0;
	while (buff[j])
		rest[i++] = buff[j++];
	rest[size] = 0;
	free(chunk);// added line
	return (rest);
}

char	*sc(int c, char *s)
{
	int	i;

	if (!s)
		return (0);
	if (!c)
		return ((char *) &s[sl(s)]);
	i = -1;
	while (s[++i])
	{
		if (c == s[i])
			return ((char *) &s[i]);
	}
	//if (!c)
	//	return ((char *) &s[i]);
	return (0);
}
