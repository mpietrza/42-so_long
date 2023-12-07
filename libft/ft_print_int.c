/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:12:20 by mpietrza          #+#    #+#             */
/*   Updated: 2023/08/09 15:09:27 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

static int	int_put_min(void)
{
	int	ret;

	ret = write(1, "-2147483648", 11);
	if (ret < 0)
		return (-1);
	return (ret);
}

static int	int_put_else(int n)
{
	int		ret;
	int		i;
	char	c;

	ret = 0;
	i = 0;
	if (n < 0)
	{
		i = write(1, "-", 1);
		if (i < 0)
			return (-1);
		ret += i;
		n = -n;
	}
	if (n >= 10)
		ret += int_put_else(n / 10);
	c = (n % 10) + '0';
	i = write(1, &c, 1);
	if (i < 0)
		return (-1);
	ret += i;
	return (ret);
}

static int	int_putnbr(int n)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	if (n == -2147483648)
	{
		i = int_put_min();
		if (i < 0)
			return (-1);
		ret += i;
	}
	else
	{
		i = int_put_else(n);
		if (i < 0)
			return (-1);
		ret += i;
	}
	return (ret);
}

int	ft_print_int(int n)
{
	int	ret;	

	ret = 0;
	if (n == 0 || n == '\0')
	{
		ret = write(1, "0", 1);
		if (ret != 1)
			return (-1);
	}
	else
	{
		ret = int_putnbr(n);
		if (ret < 0)
			return (-1);
	}
	return (ret);
}
