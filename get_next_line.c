/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:58:09 by hohu              #+#    #+#             */
/*   Updated: 2026/02/14 21:04:24 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*free_stash(char *stash)
{
	char	*new_stash;
	int		i;

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
	int		len;
	int		i;
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

static void	*gnl_free(char **stash, char **buf)
{
	if (buf && *buf)
		free(*buf);
	if (stash && *stash)
		free(*stash);
	if (buf)
		*buf = NULL;
	if (stash)
		*stash = NULL;
	return (NULL);
}

static int	reader_check(int fd, char **stash, char *buf)
{
	int	reader;

	reader = 1;
	while (!has_return(*stash) && reader > 0)
	{
		reader = read(fd, buf, BUFFER_SIZE);
		if (reader < 0)
			return (-1);
		if (reader > 0)
		{
			buf[reader] = '\0';
			*stash = join(*stash, buf);
			if (!stash)
				return (-1);
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (reader_check(fd, &stash, buf) < 0)
		return (gnl_free(&stash, &buf));
	free(buf);
	if (!stash)
		return (gnl_free(&stash, NULL));
	line = take_line(stash);
	if (!line)
		return (gnl_free(&stash, NULL));
	stash = free_stash(stash);
	return (line);
}
