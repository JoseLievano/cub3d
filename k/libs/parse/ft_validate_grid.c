/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_grid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:45:28 by jlievano          #+#    #+#             */
/*   Updated: 2025/04/24 12:45:37 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static bool	ft_line_is_empty(char *str)
{
	int	i;

	if (!str)
		return (true);
	i = 0;
	while (str[i])
	{
		if (!ft_is_space(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_has_empty_lines(t_dll *grid)
{
	t_dll	*head;
	char	*c_str;

	head = t_dll_get_head(grid);
	c_str = NULL;
	while (head)
	{
		c_str = (char *)head->content;
		if (ft_line_is_empty(c_str))
			return (true);
		head = head->next;
	}
	return (false);
}

static bool	ft_has_invalid_chars(t_dll *grid)
{
	t_dll	*head;
	char	*c_str;
	int		i;

	head = t_dll_get_head(grid);
	i = 0;
	while (head)
	{
		c_str = (char *)head->content;
		i = 0;
		while (c_str[i])
		{
			if (c_str[i] != ' ' && c_str[i] != '1' && c_str[i] != '0')
				return (true);
			i++;
		}
		head = head->next;
	}
	return (false);
}

bool	ft_valid_grid(t_dll *grid)
{
	if (!grid)
		return (false);
	if (!ft_check_zeros(grid))
		return (false);
	if (ft_has_empty_lines(grid))
		return (false);
	if (ft_has_invalid_chars(grid))
		return (false);
	return (true);
}
