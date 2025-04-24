/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_tools.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:44:13 by jlievano          #+#    #+#             */
/*   Updated: 2025/04/24 12:44:14 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

char	*nl_ft_strdup(char *str)
{
	int		mem_space;
	int		i;
	char	*new_str;

	if (!str)
		return (NULL);
	mem_space = sizeof(char) * (nl_ft_strlen(str) + 1);
	new_str = str_alloc(mem_space);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}

int	nl_ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int	has_line(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	i = -1;
	return (i);
}

char	*str_alloc(int n)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * n);
	if (!new_str)
		return (NULL);
	while (i < n)
	{
		new_str[i] = 0;
		i++;
	}
	return (new_str);
}

char	*concat_str(char *str1, char *str2)
{
	int		mem_space;
	char	*new_str;
	int		i;
	int		j;

	mem_space = sizeof(char) * (nl_ft_strlen(str1) + nl_ft_strlen(str2) + 1);
	new_str = str_alloc(mem_space);
	i = 0;
	j = 0;
	while (str1[i])
	{
		new_str[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		new_str[i] = str2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}
