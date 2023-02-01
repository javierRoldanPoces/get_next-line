/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:44:47 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/02/01 22:44:51 by Jroldan-         ###   ########.fr       */
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
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	lenght;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(s1);
	lenght = ft_strlen(s2) + ft_strlen(s1) + 1;
	s3 = (char *)malloc(lenght);
	if (s3 == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		s3[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s3[j] = s2[i];
		j++;
		i++;
	}
	s3[j] = '\0';
	return (s3);
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
