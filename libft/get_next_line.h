/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:16:37 by mpietrza          #+#    #+#             */
/*   Updated: 2023/11/23 18:34:25 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128 
# endif

# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_gnl_list
{
	char				*content;
	struct s_gnl_list	*next;
}					t_gnl_list;

char		*get_next_line(int fd);
char		*get_line(t_gnl_list *list);
char		*get_next_line(int fd);
int			len_till_newline(t_gnl_list *list);
int			search_for_newline(t_gnl_list *list);
t_gnl_list	*search_for_last_node(t_gnl_list *list);
void		buf_last_chars_of_node(t_gnl_list **list);
void		del_already_extracted(t_gnl_list **list,
				t_gnl_list *new_node, char *buf);
void		lst_create(t_gnl_list **list, int fd);
void		lst_append(t_gnl_list **list, char *buf);
void		str_from_list(t_gnl_list *list, char *str);

#endif
