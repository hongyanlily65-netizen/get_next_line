/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:19:32 by hohu              #+#    #+#             */
/*   Updated: 2026/02/08 15:59:16 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10 
#endif

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*get_line(char *stash);
char	*free_stash(char *stash);
size_t	ft_strlen(char *str);
int	has_return(char *stash);
char	*join(char  *s1, char *s2);

#endif
