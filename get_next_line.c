/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:47:05 by jroldan-          #+#    #+#             */
/*   Updated: 2023/02/05 22:14:32 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_reader(char *readed)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (readed[i] && readed[i] != '\n')
		i++;
	if(!readed[i])
	{
		free(readed);
		return(NULL);
	}
	tmp = ft_calloc((ft_strlen(readed) - i + 1), sizeof(char));
	if(!tmp)
		return(NULL);
	i++;
	j = 0;
	while(readed[i])
	{
		tmp[j] = readed[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	free(readed);
	return (tmp);
}

static char	*cpy_line(char *readed)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	j = 0;

	while (readed[i] && readed[i] != '\n')
		i++;
	line = ft_calloc(i + 1, 1);
	if (line == NULL)
		return (NULL);
	while (j <= i)
	{
		line[j] = readed[j];
		j++;
	}
	line[j] = '\0'; //no es necesario ya que al reservar memoria de 1 mas con calloc ya en la ultima posicion va pùesto
	return (line);
}
char	*read_buffer(int fd, char *readed)
{
	int	len;
	char	*buffer_temp;

	buffer_temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer_temp == NULL)
		return (NULL);	
	if (readed && (ft_strchr(readed, '\n')))
		return (readed);
	len = 1;
	if (!readed)
		readed = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (readed == NULL)
		return (NULL);

	while (len > 0)
	{
		if (len < 0)
			return (NULL);
		len = read(fd, buffer_temp, BUFFER_SIZE);
		readed = ft_strjoin(readed, buffer_temp);
		buffer_temp[len] = '\0';
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
	readed = read_buffer(fd, readed);
	if (!readed)
		return (NULL);
	//printf("\nReaded -> %s", readed);
	line = cpy_line(readed);
	readed = clean_reader(readed);
	printf(" %s", line);
	//printf("\nReaded sin line -> %s", readed);
	return (line);
}

/*
#include "get_next_line.h"

char	*clean_reader(char *readed)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	//j = ft_strlen(readed);//asigno a para contar tamaño del reader
	while (readed[i] != '\n')
		i++;
	readed = ft_substr(readed, i + 1);// pasar tamaño de readed i + 1
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
	readed = read_buffer(fd, readed);
	if (readed == NULL)
		return (NULL);
	//printf("\nReaded -> %s", readed);
	line = cpy_line(readed);
	readed = clean_reader(readed);
	printf("\nline -> %s", line);
	//printf("\nReaded sin line -> %s", readed);
	return (line);
}

*/