/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:02:04 by mpietrza          #+#    #+#             */
/*   Updated: 2023/08/09 15:00:14 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	char_conv(unsigned int num, const char format)
{
	int		ret;
	char	c;

	ret = 0;
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
	else if (num < 0)
		return (-1);
	else
		i = ft_put_hex(num, format);
	if (i < 0)
		return (-1);
	ret += i;
	if (!ret)
		return (-1);
	return (ret);
}
