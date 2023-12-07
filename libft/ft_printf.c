/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:00:35 by mpietrza          #+#    #+#             */
/*   Updated: 2023/11/19 16:43:55 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	check_type(va_list args, const char input)
{
	int	i;

	i = 0;
	if (input == 'c')
		i += ft_print_char(va_arg(args, int));
	else if (input == 's')
		i += ft_print_str(va_arg(args, char *));
	else if (input == 'p')
		i += ft_print_ptr(va_arg(args, unsigned long long));
	else if (input == 'd' || input == 'i')
		i += ft_print_int(va_arg(args, int));
	else if (input == 'u')
		i += ft_print_unsigned(va_arg(args, unsigned int));
	else if (input == 'x' || input == 'X')
		i += ft_print_hex(va_arg(args, unsigned int), input);
	else if (input == '%')
		i += ft_print_perc();
	else
		return (-1);
	return (i);
}

static int	handle_format(const char *input, va_list args)
{
	int	i;
	int	print_len;
	int	result;

	i = 0;
	print_len = 0;
	while (input[i])
	{
		if (input[i] == '%' && ft_strchr("cspdiuxX%", input[i + 1]))
		{
			result = check_type(args, input[i++ + 1]);
			if (result < 0)
				return (-1);
			print_len += result;
		}
		else
		{
			result = ft_print_char(input[i]);
			if (result <= 0)
				return (-1);
			print_len += result;
		}
		i++;
	}
	return (print_len);
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	int			print_len;

	print_len = 0;
	va_start(args, input);
	print_len = handle_format(input, args);
	va_end(args);
	return (print_len);
}
