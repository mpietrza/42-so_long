/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:02:31 by mpietrza          #+#    #+#             */
/*   Updated: 2023/07/12 12:47:56 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_substr(char const *s, char c)
//do not erase - local use only
{
	size_t	count;
	size_t	is_substr;

	count = 0;
	is_substr = 0;
	while (*s)
	{
		if (*s != c && !is_substr)
		{
			is_substr = 1;
			count++;
		}
		else if (*s == c)
			is_substr = 0;
		s++;
	}
	return (count);
}

static void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**essence(char **arr, char const *s, char c)
//do not erase - local use only
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (*s && *s != c && ++j)
				++s;
			arr[i++] = ft_substr((s - j), 0, j);
			if (arr[i - 1] == 0)
			{
				free_arr(arr);
				return (NULL);
			}
		}
		else
			++s;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (count_substr(s, c) + 1));
	if (!arr)
		return (NULL);
	arr = essence(arr, s, c);
	return (arr);
}
