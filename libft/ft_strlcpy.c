/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:30:34 by mpietrza          #+#    #+#             */
/*   Updated: 2023/06/20 15:54:04 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	if (dst_size == 0)
		return (len);
	while ((src[i] != '\0') && (i < (dst_size - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	if (dst_size > 0)
		dst[i] = '\0';
	return (len);
}
