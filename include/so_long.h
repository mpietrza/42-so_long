/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:19:46 by mpietrza          #+#    #+#             */
/*   Updated: 2023/12/02 14:36:25 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

/* definitions */
# define IMG_W 32
# define IMG_H 32
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define ARR_UP 126
# define ARR_LEFT 123
# define ARR_DOWN 125
# define ARR_RIGHT 124
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

/* struct - for storing images */
typedef struct s_img
{
	void	*player_up;
	void	*player_left;
	void	*player_down;
	void	*player_right;
	void	*background;
	void	*wall;
	void	*collectible;
	void	*exit;
}		t_img;

/* struct - for creating and managing the map */
typedef struct s_map
{
	char	**arr;
	int		x;
	int		y;
	int		collectibles;
	int		player_pos_x;
	int		player_pos_y;
}		t_map;

/* struct - for handling data */
typedef struct s_data
{
	void	*mlx;
	void	*window;
	int		size_x;
	int		size_y;
	int		pos_x;
	int		pos_y;
	int		counter;
	int		collected;
	t_map	*map;
	t_img	*img;
}		t_data;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

/* list of functions */
int		ft_1st_line_len(int fd);
int		ft_count_chars(char *s, char c);
int		ft_count_lines(int fd, t_data *data, int img_w);
void	ft_cleanup_img(t_data *data);
void	ft_cleanup_map(t_map *map);
void	ft_cleanup_data(t_data *data);
void	cleanup_and_exit(t_data *data, const char *error_message);
void	ft_error_exit(const char *error_message);
int		ft_exit(void *param);
void	ft_free_and_exit(t_data *data, const char *error_message);
void	ft_flood_fill(char **tab, t_point *size, t_point *begin);
void	ft_init_data(t_data *data);
void	ft_init_map(t_data *data);
void	ft_init_img(t_data *data);
void	ft_map_check_path(t_data *data);
void	ft_map_check_scan(t_data *data);
void	ft_map_find_start_pos(t_data *data);
void	ft_map_load_textures(t_data *data);
void	ft_map_parse(t_data *data, char **argv, int argc);
char	**ft_map_temp(t_data *data);
void	ft_move(t_data *data, char pos, int dir);
void	ft_put_background(t_data *data);
void	ft_put_object(t_data *data, void *img);
void	ft_put_player(t_data *data);
int		ft_strlen_int(const char *str);
void	ft_win(t_data *data);
void	ft_window_size(t_data *data, char **argv);

#endif
