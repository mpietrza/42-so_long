/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:27:55 by mpietrza          #+#    #+#             */
/*   Updated: 2023/08/09 14:31:11 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*ch;
	int		len;

	len = ft_num_len(n);
	ch = (char *)malloc(sizeof(char) * (len + 1));
	if (!ch)
		return (NULL);
	ch[len] = '\0';
	while (n != 0)
	{
		ch[len-- - 1] = n % 10 + '0';
		n = n / 10;
	}
	return (ch);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_len;
	char	*ch;

	print_len = 0;
	if (n == 0)
		print_len += write(1, "0", 1);
	else if (n > 0)
	{
		ch = ft_uitoa(n);
		if (ch == NULL)
			return (-1);
		print_len += ft_print_str(ch);
		free(ch);
	}
	else
		return (-1);
	return (print_len);
}
