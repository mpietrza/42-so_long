/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:33:41 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/05 17:28:43 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;*/

int		ft_printf(const char *input, ...);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_unsigned(unsigned int n);
int		ft_print_str(char *s);
int		ft_print_int(int num);
int		ft_print_char(char c);
int		ft_print_hex(unsigned int num, const char format);
int		ft_print_perc(void);

#endif
