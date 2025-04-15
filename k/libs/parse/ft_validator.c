#include "ft_parse.h"

static bool	check_file(char *file)
{
	int	len;
	int	fd;

	if (file == NULL)
		return (false);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return false;
	close(fd);
	len = ft_strlen(file);
	if (len < 5)
		return (false);
	if (file[len - 4] != '.' || file[len - 3] != 'c' ||
		file[len - 2] != 'u' || file[len - 1] != 'b')
		return (false);
	return (true);
}

bool ft_validator(int argc, char **argv)
{
	bool res;

	res = false;
	if (argc < 2)
		return (false);
	res = check_file(argv[1]);
	return (res);
}