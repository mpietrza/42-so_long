/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:31:18 by mpietrza          #+#    #+#             */
/*   Updated: 2023/11/23 17:05:54 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*get_line(t_gnl_list *list)
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = len_till_newline(list);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	str_from_list(list, next_str);
	return (next_str);
}

void	lst_create(t_gnl_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!search_for_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		lst_append(list, buf);
	}
}

void	lst_append(t_gnl_list **list, char *buf)
{
	t_gnl_list	*new_node;
	t_gnl_list	*last_node;

	last_node = search_for_last_node(*list);
	new_node = malloc(sizeof(t_gnl_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

void	buf_last_chars_of_node(t_gnl_list **list)
{
	t_gnl_list	*last_node;
	t_gnl_list	*new_node;
	int			i;
	int			j;
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_gnl_list));
	if (buf == NULL || new_node == NULL)
		return ;
	last_node = search_for_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] && last_node->content[++i])
		buf[j++] = last_node->content[i];
	buf[j] = '\0';
	new_node->content = buf;
	new_node->next = NULL;
	del_already_extracted(list, new_node, buf);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*list = NULL;
	char				*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	lst_create(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	buf_last_chars_of_node(&list);
	return (next_line);
}
