/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:24:48 by jlievano          #+#    #+#             */
/*   Updated: 2024/03/04 00:29:24 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function calculates the total memory space needed for the joined string.
static unsigned int	calculate_memory_space(const char *s1, const char *s2)
{
	return (sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
}

// This function copies s1 and s2 into new_str.
static void	copy_strings(char *new_str, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		new_str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		new_str[j++] = s2[i++];
	}
	new_str[j] = '\0';
}

// The main function that joins two strings.
char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	mem_space;
	char			*new_str;

	if (!s1 || !s2)
		return (NULL);
	mem_space = calculate_memory_space(s1, s2);
	new_str = (char *)malloc(mem_space);
	if (!new_str)
		return (NULL);
	copy_strings(new_str, s1, s2);
	return (new_str);
}
