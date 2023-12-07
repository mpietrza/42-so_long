/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:18:02 by mpietrza          #+#    #+#             */
/*   Updated: 2023/06/22 15:45:12 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	char	ch;

	ch = (char)c;
	i = ft_strlen(s);
	ptr = NULL;
	while (i >= 0)
	{
		if (s[i] == ch)
		{
			ptr = (char *) &s[i];
			return (ptr);
		}
		i--;
	}
	if (ch == '\0')
	{
		ptr = (char *) &s[i];
		return (ptr);
	}
	return (NULL);
}
