/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:05:41 by mpietrza          #+#    #+#             */
/*   Updated: 2023/07/12 12:49:31 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

size_t static	int_len(int n)
{
	size_t	len;

	if (n == -2147483648)
		len = 11;
	else
	{
		len = 1;
		if (n < 0)
			n = -n;
		else if (n > 0)
			len = 0;
		while (n)
		{
			n /= 10;
			len++;
		}
	}
	return (len);
}

char static	pos_neg_0(long int ln)
{
	char	symbol;

	symbol = '\0';
	if (ln < 0)
		symbol = '-';
	else if (ln == 0)
		symbol = '0';
	else
		symbol = '\0';
	return (symbol);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	char		symbol;
	long int	ln;

	len = int_len(n);
	ln = (long int)n;
	symbol = pos_neg_0(ln);
	if (ln < 0)
		ln = -ln;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (ln > 0)
	{
		str[--len] = ln % 10 + '0';
		ln /= 10;
	}
	if (symbol)
		str[0] = symbol;
	return (str);
}
