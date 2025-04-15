#include "ft_parse.h"

static bool	check_file(char *file)
{
	int	len;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return false;
	len = ft_strlen(file);

}

bool ft_validator(int argc, char **argv)
{

}