/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:47:05 by jroldan-          #+#    #+#             */
/*   Updated: 2023/02/01 23:37:30 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffer(int fd, char *buffer, char *readed)
{
	int	i;
	int	j;
	int	count;
	int	len;

	i = 0;
	j = 0;
	count = 0;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	len = read(fd, buffer, BUFFER_SIZE);
	readed = ft_strjoin(readed, buffer);
	/*while (buffer[i] != '\n')
		count++;*/
	write(1, buffer, len);
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
// sigurinte paso ver como incializo la static y ver cuando concateno diferenciando que se haya vuelto
// a llamar a gnl