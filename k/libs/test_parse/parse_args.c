/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:42:29 by vflores-          #+#    #+#             */
/*   Updated: 2025/03/20 14:00:36 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

/* Verifica si el argumento proporcionado es un dir.
 * Devuelve true si es un dir, de lo contrario false.
 */

static bool	is_dir(const char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (true);
	}
	return (false);
}

/* Verifica si el archivo tiene la extension .cub
 * Devuelve true si cumple con el formato, false en caso contrario.
 */

static bool	is_cub_ext(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	if (filename[len - 4] == '.'
		&& filename[len - 3] == 'c'
		&& filename[len - 2] == 'u'
		&& filename[len - 1] == 'b')
		return (true);
	return (false);
}

/*Comprueba si el archivo tiene la extension .xpm
 * Retorna true si la externsion es valida, de lo contrario false.
 */

static bool	is_xmp_ext(const char *filepath)
{
	size_t	len;

	len = ft_strlen(filepath);
	if (len < 4)
		return (false);
	if (filepath[len - 4] == '.'
		&&filepath[len - 3] == 'x'
		&&filepath[len - 2] == 'p'
		&&filepath[len - 1] == 'm')
		return (true);
	return (false);
}

/* Verifica si el archivo proporcionado cumple con los requisitos
 * necesarios. Si el archivo es un directorio, no existe, no es 
 * accesible, o no tiene la extension esperada (.cub o .xpm), 
 * devuelve un codigo de error. Retorna SUCCESS si el archivo pasa
 * las verificaciones.
 */

int	check_file(const char *args, bool cub)
{
	int	fd;

	if (is_dir(args))
	{
		printf("ERROR: %s es un directorio, no un archivo\n", args);
		return (error_msg(args, ERR_FILE_IS_DIR, FAILURE));
	}
	fd = open(args, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR: no se puede abrir el archivo %s, %s\n", args, strerror(errno));
		return (error_msg(args, strerror(errno), FAILURE));
	}
	close(fd);
	if (cub && !is_cub_ext(args))
	{
		printf("ERROR: El archivo no tiene extension .cub\n");
		return (error_msg(args, ERR_FILE_NOT_CUB, FAILURE));
	}
	if (!cub && !is_xmp_ext(args))
	{
		printf("ERROR: El archivo no tiene extension .xpm\n");
		return (error_msg(args, ERR_FILE_NOT_XPM, FAILURE));
	}
	return (SUCCESS);
}
