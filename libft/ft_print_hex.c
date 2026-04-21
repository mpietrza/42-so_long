/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:02:04 by mpietrza          #+#    #+#             */
/*   Updated: 2026/04/21 22:42:32 by milosz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	char_conv(unsigned int num, const char format)
{
	char	c;

	if (format == 'x')
		c = num - 10 + 'a';
	else if (format == 'X')
		c = num - 10 + 'A';
	else
		return (-1);
	if (c < 0)
		return (-1);
	return (c);
}

static int	ft_put_hex(unsigned int num, const char format)
{
	int		ret;
	char	c;

	ret = 0;
	if (num >= 16)
	{
		ret += ft_put_hex(num / 16, format);
		ret += ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			c = num + '0';
		else
			c = char_conv(num, format);
		if (!c)
			return (-1);
		ret += write(1, &c, 1);
	}
	if (ret < 0)
		return (-1);
	return (ret);
}

int	ft_print_hex(unsigned int num, const char format)
{
	int	ret;
	int	i;

	ret = 0;
	if (num == 0)
		i = write(1, "0", 1);
	else
		i = ft_put_hex(num, format);
	if (i < 0)
		return (-1);
	ret += i;
	if (!ret)
		return (-1);
	return (ret);
}
