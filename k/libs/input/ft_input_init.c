/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:52:44 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/19 17:52:46 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_input.h"

t_input	*ft_input_init(void)
{
	t_input	*input;

	input = (t_input *)malloc(sizeof(t_input));
	if (!input)
		return (NULL);
	input->up = false;
	input->right = false;
	input->down = false;
	input->left = false;
	input->r_l = false;
	input->r_r = false;
	input->esc = false;
	input->mouse_x = 0;
	return (input);
}
