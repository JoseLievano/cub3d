/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:33:57 by vflores-          #+#    #+#             */
/*   Updated: 2025/03/11 15:20:23 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

int	error_msg(const char *context, char *msg, int exit_code)
{
	ft_putstr_fd(RED "cub3d: Error", 2);
	if (context)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(context, 2);
	}
	if (msg)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg, 2);
	}
	ft_putstr_fd("\n" RESET, 2);
	return (exit_code);
}

int	error_msg_val(int context, char *msg, int exit_code)
{
	ft_putstr_fd(RED "cub3d: Error: ", 2);
	ft_putnbr_fd(context, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n" RESET, 2);
	return (exit_code);
}
