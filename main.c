#include <fcntl.h>  // Para open()
#include <stdio.h>  // Para printf()
#include "get_next_line.h"  // Incluir tu header

int	main(void)
{
	int		fd;
	char	*line;

	// 1️⃣ Abrir el archivo de prueba
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("❌ Error al abrir el archivo.\n");
		return (1);
	}

	// 2️⃣ Leer línea por línea usando get_next_line()
	while ((line = get_next_line(fd)))
	{
		printf("📖 Línea leída: %s \n", line);
		free(line); // No olvides liberar la memoria de cada línea leída
	}

	// 3️⃣ Cerrar el archivo
	close(fd);
	printf("✅ Fin de la lectura del archivo.\n");
	return (0);
}
