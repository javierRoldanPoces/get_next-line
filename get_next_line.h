/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:47:02 by jroldan-          #+#    #+#             */
/*   Updated: 2023/02/08 13:52:16 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char *readed, const char *buffer);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s);
char	*clean_reader(char *readed);
char	*ft_substr(char const *s, unsigned int start);
size_t	ft_strlen(const char *s);
#endif