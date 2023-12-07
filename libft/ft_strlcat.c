/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:22:14 by mpietrza          #+#    #+#             */
/*   Updated: 2023/06/20 16:20:26 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	offset;
	size_t	src_index;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dstsize <= d_len)
		return (dstsize + s_len);
	offset = d_len;
	src_index = 0;
	while ((*(src + src_index) != '\0') && (offset != dstsize - 1))
	{
		*(dst + offset) = *(src + src_index);
		offset++;
		src_index++;
	}
	*(dst + offset) = '\0';
	return (d_len + s_len);
}
