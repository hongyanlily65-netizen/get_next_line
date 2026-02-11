/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:58:09 by hohu              #+#    #+#             */
/*   Updated: 2026/02/11 20:42:38 by hohu             ###   ########.fr       */
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

char	*free_stash(char *stash)
{
	char	*new_stash;
	int	i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	if (stash[i + 1] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_substr(stash, i + 1, ft_strlen(stash) - (i + 1));
	free(stash);
	return (new_stash);
}

char	*take_line(char *stash)
{
	int	len;
	int	i;
	char	*line;

	len = 0;
	if (!stash)
		return (NULL);
	while (stash[len] != '\n' && stash[len])
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*stash;
	int		reader;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!has_return(stash))
	{
		reader = read(fd, buf, BUFFER_SIZE);
		if (reader == -1)
		{
			free (buf);
			free (stash);
			stash = NULL;
			return (NULL);
		}
		if (reader == 0)
			break ;
		buf[reader] = '\0';
		stash = join(stash, buf);
		if (!stash || stash[0] == '\0')
		{
			free(buf);
			free(stash);
			return (NULL);
		}
	}
	free(buf);
	line = take_line(stash);
	stash = free_stash(stash);
	return (line);
}
