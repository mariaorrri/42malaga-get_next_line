#include <fcntl.h>  // open()
#include <stdio.h>  // printf()
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	// Abrir el archivo de prueba
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo.\n");
		return (1);
	}

	// Leer línea por línea usando get_next_line()
	line = get_next_line(fd);
	while (line)
	{
		printf("Línea leída: %s ", line);
		free(line); // liberar la memoria de cada línea leída
		line = get_next_line(fd);
	}

	// Cerrar el archivo
	close(fd);
	printf("Fin de la lectura del archivo.\n");
	return (0);
}
