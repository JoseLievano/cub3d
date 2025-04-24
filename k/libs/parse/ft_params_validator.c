/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_validator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:49:28 by jlievano          #+#    #+#             */
/*   Updated: 2025/04/24 12:44:53 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static void	throw_incorrect_file_extension(void)
{
	printf("Error\nIncorrect file extension");
	exit(EXIT_FAILURE);
}

static int	check_file(char *file)
{
	int	len;
	int	fd;

	if (file == NULL)
		return (false);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCan't open this file :(");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(file);
	if (len < 5)
		throw_incorrect_file_extension();
	if (file[len - 4] != '.' || file[len - 3] != 'c'
		|| file[len - 2] != 'u' || file[len - 1] != 'b')
		throw_incorrect_file_extension();
	return (fd);
}

int	ft_params_validator(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		printf("Error\nInvalid number of arguments");
		exit(EXIT_FAILURE);
	}
	fd = check_file(argv[1]);
	return (fd);
}
