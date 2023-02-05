/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:46:29 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/02/05 20:33:17 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fichero;
	char	*buff;
	int		len;

	fichero = open("file.txt", O_RDONLY);
	if (fichero == -1)
	{
		printf("Error al abrir el fichero");
		return (-1);
	}		
	/*len = read(fichero, &buff, 50000);
	write(1, *buff, len);
	printf("%i", len);*/
	get_next_line(fichero);
	get_next_line(fichero);
	get_next_line(fichero);
	get_next_line(fichero);
	get_next_line(fichero);
	get_next_line(fichero);
	get_next_line(fichero);
	get_next_line(fichero);
	close(fichero);
	return (0);
}
