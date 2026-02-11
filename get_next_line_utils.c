/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:52:00 by hohu              #+#    #+#             */
/*   Updated: 2026/02/11 20:19:56 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	has_return(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*join(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	size_t	j;
	char	*stash;

	if (s1)
		s1len = ft_strlen(s1);
	else
		s1len = 0;
	if (!s2)
		return (free(s1), NULL);
	s2len = ft_strlen(s2);
	stash = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!stash)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (i < s1len)
	{
		stash[i] = s1[i];
		i++;
	}
	while (j < s2len)
	{
		stash[i + j] = s2[j];
		j++;
	}
	stash[i + j] = '\0';
	free(s1);
	return (stash);
}
