/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:19:34 by mpietrza          #+#    #+#             */
/*   Updated: 2023/06/14 14:32:45 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return ((c >= 'A') && (c <= 'Z'));
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		c = c + 32;
	return (c);
}
