/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:19:32 by hohu              #+#    #+#             */
/*   Updated: 2026/02/11 20:41:20 by hohu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2 
#endif

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

char	*ft_substr(char *stash, int start, size_t new_len);
char	*get_next_line(int fd);
char	*take_line(char *stash);
char	*free_stash(char *stash);
int	has_return(char *stash);
char	*join(char  *s1, char *s2);
size_t  ft_strlen(char *str);


#endif
