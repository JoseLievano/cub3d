#include "ft_parse.h"

int	holder_cleaner(char *holder, int clean)
{
	if (clean)
	{
		free(holder);
		return (1);
	}
	else
		return (0);
}
