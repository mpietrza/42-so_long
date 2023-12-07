/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:58:58 by mpietrza          #+#    #+#             */
/*   Updated: 2023/06/22 13:49:41 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*ptr;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == ch)
		{
			ptr = (char *) &s[i];
			return (ptr);
		}
		i++;
	}
	if (ch == '\0')
	{
		ptr = (char *) &s[i];
		return (ptr);
	}
	return (NULL);
}
