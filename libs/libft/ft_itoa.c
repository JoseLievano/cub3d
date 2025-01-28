/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:10:50 by jlievano          #+#    #+#             */
/*   Updated: 2024/03/03 23:12:19 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int number)
{
	int	count;

	if (number == 0)
	{
		count = 1;
	}
	else
	{
		count = 0;
	}
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

static int	is_negative(int number)
{
	if (number < 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static char	*memory_allocation(int amount_digits, int is_negative)
{
	char	*str;

	if (is_negative)
	{
		str = (char *)malloc(sizeof(char) * (amount_digits + 2));
		if (!str)
			return (NULL);
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (amount_digits + 1));
		if (!str)
			return (NULL);
	}
	return (str);
}

static char	*get_str(char *str, int number, int amount_digits, int is_negative)
{
	int	i;

	i = 0;
	if (is_negative)
		i = 1;
	if (is_negative)
		str[0] = '-';
	str[amount_digits + i] = '\0';
	while (amount_digits > 0)
	{
		str[amount_digits + i - 1] = (number % 10) + '0';
		number /= 10;
		amount_digits--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	amount_digits;
	char	*str;
	int		neg_flag;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg_flag = is_negative(n);
	if (neg_flag)
		n *= -1;
	amount_digits = digit_count(n);
	str = memory_allocation(amount_digits, neg_flag);
	if (!str)
		return (NULL);
	return (get_str(str, n, amount_digits, neg_flag));
}
