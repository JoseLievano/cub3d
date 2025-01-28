/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:56:51 by jlievano          #+#    #+#             */
/*   Updated: 2024/03/04 00:58:48 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	find_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	return (start);
}

static size_t	find_end(char const *s1, char const *set, size_t start)
{
	size_t	end;

	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	return (end);
}

static char	*create_trimmed_str(char const *s1, size_t start, size_t end)
{
	char	*trimmed_str;

	trimmed_str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!trimmed_str)
		return (NULL);
	if (start >= end)
		trimmed_str[0] = '\0';
	else
		ft_strlcpy(trimmed_str, s1 + start, end - start + 1);
	return (trimmed_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
	{
		if (!s1)
			return (NULL);
		else
			return (ft_strdup(s1));
	}
	start = find_start(s1, set);
	end = find_end(s1, set, start);
	return (create_trimmed_str(s1, start, end));
}
