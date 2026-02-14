/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:19:16 by hohu              #+#    #+#             */
/*   Updated: 2026/02/14 20:58:32 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
/*
int	main(void)
{
	int	fd;
	char	*s;

	fd = open("file2.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	while((s = get_next_line(fd))!= NULL)
	{
		printf("The next line is:%s", s);
		free(s);
	}
	printf("%p", s);
	close(fd);
	return (0);
}	
*/
int	main(int argc,char **argv)
{
	int	fd;
	int	n;
	char	*line;
	
	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	n = 1;
	while (line)
	{
		printf("line %i:\n %s", n, line);
		free(line);
		line = get_next_line(fd);
		n++;
	}
	close(fd);
	return (0);
}
