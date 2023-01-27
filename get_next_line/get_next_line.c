/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroldan- <jroldan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:47:05 by jroldan-          #+#    #+#             */
/*   Updated: 2023/01/27 18:09:19 by jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	buffer[100];
	char		line[50];
	int			size_line;
	
}

//Entiendo que debo leer hasta fin de linea \n  y hasta final de fichero que sera cuando
//la funcion read devuelva 0 ( o -1 ?¿?¿)
//La función read() de C devuelve el número de bytes leídos. Si no lee nada, devuelve 0.
// Si se produce un error, devuelve -1.
// Duda que tamaño tengo que dar al string que guarda la linea supongo que se determinara de forma dinámica
