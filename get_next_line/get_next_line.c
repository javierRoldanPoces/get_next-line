/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:47:05 by jroldan-          #+#    #+#             */
/*   Updated: 2023/02/03 13:58:16 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_reader(char *readed)
{
	unsigned int	i;
	int j;

	i = 0;
	j = ft_strlen(readed);//asigno a para contar tamaño del reader
	while (readed[i] != '\n')
	{
		i++;
	}
	readed = ft_substr(readed, i + 1);// pasar tamaño de readed -i + 1
	return (readed);
}

char	*cpy_line(char *readed)
{
	size_t	i;
	size_t	j;
	char	*line;

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
	return (line);
}

char	*read_buffer(int fd, char *readed)
{
	size_t	len;
	char	*buffer_temp;

	if (readed && (ft_strchr(readed, '\n')))
		return (readed);
	len = 1;
	if (!readed)
		readed = calloc (1, 1);
	if (readed == NULL)
		return (NULL);
	buffer_temp = ft_calloc(BUFFER_SIZE + 1, 1);
	if (buffer_temp == NULL)
		return (NULL);
	while (len > 0)
	{
		if (len < 0)
			return (NULL);
		len = read(fd, buffer_temp, BUFFER_SIZE);
		readed = ft_strjoin(readed, buffer_temp);
		buffer_temp[len] = 0;
		if ((ft_strchr(buffer_temp, '\n')))
			break ;	
	}
	free(buffer_temp);
	return (readed);
}

char	*get_next_line(int fd)
{
	static char		*readed;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	/*readed = ft_calloc(1, 1);
	if (readed == NULL)
		return (NULL);*/
	readed = read_buffer(fd, readed);
	//printf("\nReaded -> %s", readed);
	line = cpy_line(readed);
	readed = clean_reader(readed);
	printf("\nline -> %s", line);
	//printf("\nReaded sin line -> %s", readed);
	return (line);
}
