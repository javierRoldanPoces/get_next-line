#include "get_next_line_bonus.h"

int	main(void)
{
	int	fichero00;
	int	fichero01;
	char	*line0;
	char	*line01;
	int	i;

	i = 0;
	fichero00 = open("file.txt", O_RDONLY);
	if (fichero00 == -1)
	{
		printf("Error al abrir el fichero");
		return (-1);
	}
	fichero01 = open("file00.txt", O_RDONLY);
	if (fichero01 == -1)
	{
		printf("Error al abrir el fichero");
		return (-1);
	}
	// line01 = get_next_line(fichero01);
	// printf("%s\n", line01);
	while (line01 != NULL)
	{	
		line01 = get_next_line(fichero01);
		printf("%s\n", line01);
	}
	while (line0 != NULL)
	{	
		line0 = get_next_line(fichero00);
		printf("%s\n", line0);
	}
	close(fichero01);
	close(fichero00);
	return (0);
}
