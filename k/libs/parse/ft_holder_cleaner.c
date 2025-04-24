/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_holder_cleaner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:44:33 by jlievano          #+#    #+#             */
/*   Updated: 2025/04/24 12:44:34 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
