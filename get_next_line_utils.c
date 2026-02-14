/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:52:00 by hohu              #+#    #+#             */
/*   Updated: 2026/02/14 21:05:03 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *stash, int start, size_t new_len)
{
	size_t	i;
	char	*sub_stash;

	sub_stash = malloc(new_len + 1);
	if (!sub_stash)
		return (NULL);
	i = 0;
	while (i < new_len)
	{
		sub_stash[i] = stash[start + i];
		i++;
	}
	sub_stash[i] = '\0';
	return (sub_stash);
}

size_t	ft_strlcpy(char *dest, char *src, size_t n)
{
	size_t	i;

	if (n == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < n -1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

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
		if (stash[i] == 'a')
			return (1);
		i++;
	}
	return (0);
}

char	*join(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
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
	ft_strlcpy(stash, s1, s1len + 1);
	ft_strlcpy(stash + s1len, s2, s2len + 1);
	free(s1);
	return (stash);
}
