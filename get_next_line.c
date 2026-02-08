/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:58:09 by hohu              #+#    #+#             */
/*   Updated: 2026/02/08 17:26:25 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	char	*res;
	int		len_s;
	int		i;

	len_s = ft_strlen(s);
	res = malloc(len_s + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char *stash, int start, size_t new_len)
{
	size_t	slen;
	size_t	sub_len;
	int	i;
	char	*sub_stash;
	
	slen = ft_strlen(stash);
	if (start >= slen)
		return (ft_strdup(""));
	sub_len = slen - start;
	if (sub_len > new_len)
		sub_len = new_len;
	sub_stash = malloc(sub_len + 1);
	if (!sub_stash)
		return (NULL);
	i = 0;
	while (i < sub_len)
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
	int	j;
	size_t	new_len;
	
	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_len = ft_strlen(stash) - (i + 1) + 1;
	new_stash = ft_substr(stash, i + 1, new_len);
	new_stash[j] = '\0';
	free(stash);
	return(new_stash);
}

char	*get_line(char *stash)
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
	if (!(line = malloc(sizeof(char) * (len + 1))))
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

	if (fd < 0|| BUFFER_SIZE <= 0)
		return (NULL);
	if (!(buf = malloc(sizeof(char)*(BUFFER_SIZE + 1))))	
		return (NULL);
	reader = 1;
	while (!has_return(stash) && reader != 0)
	{	
		reader = read(fd, buf, BUFFER_SIZE);
		if (reader == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[reader] = '\0';
		stash = join(stash, buf);
	}
	free (buf);
	line = get_line(stash);
	stash = free_stash(stash);
	return(line);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
