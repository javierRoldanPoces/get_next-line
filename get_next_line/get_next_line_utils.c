/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:44:47 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/02/03 12:45:47 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{	
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	char		*scpy;

	scpy = (char *) s;
	i = 0;
	while (i < n)
	{
		scpy[i] = (char)c;
		i++;
	}
	return (s = scpy);
}

/*void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*c;

	c = malloc(count * size);
	if (c == NULL)
		return (NULL);
	ft_memset(c, 0, size);
	return (c);
}

// strjoin strchr
/**
 * @def Reserva con malloc y devuelve una nueva string, formada por la 
 * concatenación de ’s1’ y ’s2’.Devuelve el string nuevo null si falla la 
 * reserva de memoria 
 * 
 * @param s1 -> primera string 
 * @param s2 ->  string destino donde se concatena s1
 * @return char* -> nueva string formada x concatenacion s2 y s1
 */
char	*ft_strjoin(char *readed, const char *buffer)
{
	char	*jointed;
	size_t	lenght;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(readed);
	lenght = ft_strlen(buffer) + ft_strlen(readed) + 1;
	jointed = calloc(1, lenght);
	if (jointed == NULL)
		return (NULL);
	while (readed[j] != '\0')
	{
		jointed[j] = readed[j];
		j++;
	}
	i = 0;
	while (buffer[i] != '\0')
	{
		jointed[j] = buffer[i];
		j++;
		i++;
	}
	free(readed);
	return (jointed);
}

char	*ft_strchr(const char *s, int c)
{
	char	*scpy;

	scpy = (char *)s;
	if ((char)c == '\0')
		return (&(scpy[ft_strlen(scpy)]));
	while (*s != '\0')
	{
		if ((*s) == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
/**
 * @def Reserva con malloc(3) y devuelve substring de s,la substring empieza 
 * 		desde el indice start, su longitud máx es len.
 * @note Controlo que si el tam de origen-primera_posicion sea menor que 
 * tamdestino en tal caso el tamaño	tamdestino(len)= tamorigen-primera 
 * posicion si no lo hago no reservo bien la memoria.
 * @param s String desde la que creamos la substring
 * @param start Índice del caracter en s desde el que empezar la substring
 * @param len longitud máxima de la substring
 * @return char* La substring resultante Null si falla la reserva de memoria
 */
char	*ft_substr(char const *s, unsigned int start)
{
	char	*substring;
	size_t	startcast;
	size_t	tam;
	size_t	len;

	len = BUFFER_SIZE;
	startcast = (size_t)start;
	tam = 0;
	if (ft_strlen(s) == 0)
		return (ft_strdup(""));
	if (ft_strlen(s) < startcast)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (substring == NULL)
		return (NULL);
	while (tam < len)
	{
		substring[tam] = s[startcast];
		tam++;
		startcast++;
	}
	substring[tam] = '\0';
	return (substring);
}
/**
 * @def La función strdup() devuelve un puntero a la cadena duplicada, o NULL si 
		no había bastante memoria La memoria para la nueva cadena se obtiene 
		automáticamente con malloc(3) y puede(y debe) liberarse con free
 * 
 * @param s 
 * @return char* Devuelve un puntero a una nueva cadena de caracteres que
 *  es un duplicado de la cadena apuntada por s.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < (size -1) && src[i] != '\0')
		{	
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	char	*cpys;
	char	*d;

	cpys = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (cpys == NULL)
		return (NULL);
	d = (char *)s;
	ft_strlcpy(cpys, d, ft_strlen(s)+1);
	return (cpys);
}
