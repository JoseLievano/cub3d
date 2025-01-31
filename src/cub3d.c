#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	ft_game();
	ft_parse();
	if (argc == 2)
		printf("%s\n", argv[1]);
	else
		printf("Error\nInvalid number of arguments\n");
	return (0);
}