/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:47:05 by jroldan-          #+#    #+#             */
/*   Updated: 2023/02/02 20:49:08 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cpy_line(char *readed, char *line, size_t *len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (readed[i] != '\n')
	{
		i++;
	}
	line = calloc(1, i + 1);
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
		line[j] = readed[j];
		j++;
	}
	readed = ft_substr(readed, i, len);
	printf("\nReaded sin line cpy_line -> %s", readed);
	printf("\nline -> %s", line);
	return (line);
}

static char	*read_buffer(int fd, char *buffer, char *readed, char *line, size_t *len)
{
	buffer = ft_calloc(BUFFER_SIZE, 1);
	if (buffer == NULL)
		return (NULL);
	if (!readed)
	{
		readed = calloc (1, 1);
	}
	while (*len > 0)
	{
		if (*len < 0)
			return (NULL);
		*len = read(fd, buffer, BUFFER_SIZE);
		readed = ft_strjoin(readed, buffer);
		if ((ft_strchr(buffer, '\n')))
			break ;
	}
	free(buffer);
//	line = cpy_line(readed, line, len);
	
	printf("\nReaded -> %s", readed);
	return (readed);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*readed;
	char		*line;
	size_t		len;

	len = 1;
	readed = read_buffer(fd, buffer, readed, line, &len);
	line = cpy_line(readed, line, &len);
	printf("\nReaded sin line -> %s", readed);

	return (line);
}
