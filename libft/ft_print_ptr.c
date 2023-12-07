/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:14:35 by mpietrza          #+#    #+#             */
/*   Updated: 2023/11/08 16:50:57 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_put_ptr(uintptr_t num)
{
	int		ret;
	char	c;

	ret = 0;
	if (num >= 16)
	{
		ret += ft_put_ptr(num / 16);
		ret += ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			c = num + '0';
		else
			c = num - 10 + 'a';
		if (!c)
			return (-1);
		ret += write(1, &c, 1);
	}
	return (ret);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	ret;
	int	i;

	ret = 0;
	i = write(1, "0x", 2);
	if (i < 0)
		return (-1);
	ret += i;
	if (ptr == 0)
		i = write(1, "0", 1);
	else
		i = ft_put_ptr(ptr);
	if (i < 0)
		return (-1);
	ret += i;
	if (!ret)
		return (-1);
	return (ret);
}
