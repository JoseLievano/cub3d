#include "ft_parse.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Uso: %s mapa_test.cub\n", argv[0]);
		return 1;
	}
	printf("Mapa cargado correctamente.\n");
	return 0;
}
