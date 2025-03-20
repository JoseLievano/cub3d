#include "ft_parse.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Uso: %s mapa_test.cub\n", argv[0]);
		return 1;
	}
	t_data game_data;
	parse_data(argv[1], &game_data);

	printf("Mapa cargado correctamente.\n");
	return 0;
}
