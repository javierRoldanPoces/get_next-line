/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:44:47 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/02/02 18:06:49 by Jroldan-         ###   ########.fr       */
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

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;

	c = malloc(count * size);
	if (c == NULL)
		return (NULL);
	ft_bzero(c, count * size);
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
