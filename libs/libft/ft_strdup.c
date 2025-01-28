/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:20:52 by jlievano          #+#    #+#             */
/*   Updated: 2024/03/04 00:22:37 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	str_len;
	char	*new_str;

	str_len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, str, str_len + 1);
	return (new_str);
}
