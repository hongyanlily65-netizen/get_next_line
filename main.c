/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:19:16 by hohu              #+#    #+#             */
/*   Updated: 2026/02/08 15:30:43 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*s;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	while((s = get_next_line(fd))!= NULL)
	{
		printf("The next line is:%s", s);
		free(s);
	}
	close(fd);
	return (0);
}	
