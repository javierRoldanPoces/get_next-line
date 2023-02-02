/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:46:29 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/02/02 20:09:54 by Jroldan-         ###   ########.fr       */
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
	//get_next_line(fichero);
	//get_next_line(fichero);
	close(fichero);
	return (0);
}
