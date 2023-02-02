/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:47:05 by jroldan-          #+#    #+#             */
/*   Updated: 2023/02/02 18:23:33 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
static char	*cpy_line(char *readed. char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (readed[i] != '\n')
	{
		i++;
	}
	line = malloc(1, i + 1);
	
	while (i)
}*/
static char	*read_buffer(int fd, char *buffer, char *readed)
{
	int	len;

	len = 1;
	buffer = ft_calloc(BUFFER_SIZE, 1);
	if (buffer == NULL)
		return (NULL);
	if (!readed)
	{
		readed = calloc (1, 1);
	}
	while (len > 0)
	{
		if (len < 0)
			return (NULL);
		len = read(fd, buffer, BUFFER_SIZE);
		readed = ft_strjoin(readed, buffer);
		if ((ft_strchr(buffer, '\n')))
			break ;
	}
	free(buffer);
	printf("%s", readed);
	return (readed);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*readed;
	char		*line;

	read_buffer(fd, buffer, readed);
	return (line);
}

//Entiendo que debo leer hasta fin de linea \n  y hasta final de fichero que sera cuando
//la funcion read devuelva 0 ( o -1 ?¿?¿)
//La función read() de C devuelve el número de bytes leídos. Si no lee nada, devuelve 0.
// Si se produce un error, devuelve -1.
// Duda que tamaño tengo que dar al string que guarda la linea supongo que se determinara de forma dinámica

// linea 21  guardo los caracteres que leo por si es menor
// siguiente paso ver como incializo la static y ver cuando concateno diferenciando que se haya vuelto
// a llamar a gnl
