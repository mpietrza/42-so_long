/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:19:46 by mpietrza          #+#    #+#             */
/*   Updated: 2026/04/21 22:41:51 by milosz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

/* definitions */
# define IMG_W 32
# define IMG_H 32
# define ESC XK_Escape
# define W XK_w
# define A XK_a
# define S XK_s
# define D XK_d
# define ARR_UP XK_Up
# define ARR_LEFT XK_Left
# define ARR_DOWN XK_Down
# define ARR_RIGHT XK_Right
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

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
	t_point	*map_size;
	t_point	*player_pos;
	int		x;
	int		y;
	int		collectibles;
}		t_map;

/* struct - for handling data */
typedef struct s_data
{
	t_map	*map;
	void	*mlx;
	void	*window;
	int		size_x;
	int		size_y;
	int		pos_x;
	int		pos_y;
	int		counter;
	int		collected;
	t_img	*img;
}		t_data;

/* list of functions */
int		ft_count_chars(char *s, char c);
void	ft_clup_img(t_data *data);
void	ft_clup_map(t_map *map);
void	ft_clup_map_size(t_point *map_size);
void	ft_clup_data(t_data *data);
void	ft_clup_and_exit(t_data *data, const char *error_message);
void	ft_clup_map_and_exit(t_map *map, const char *error_message);
void	ft_cleanup_map_array(char **arr, int j);
void	ft_error_exit(const char *error_message);
int		ft_exit(void *param);
void	ft_flood_fill(char **tab, t_point *size, t_point *begin);
t_data	*ft_init_data(t_map *map);
t_map	*ft_init_map(char *buf_for_arr, t_point *map_size);
void	ft_map_checks(t_map *map);
void	ft_map_check_path(t_map *map);
void	ft_map_check_scan(t_map *map);
void	ft_map_find_start_pos(t_map *map);
void	ft_map_load_textures(t_data *data);
char	*ft_map_parse(int fd, t_point *map_size);
char	**ft_map_str_to_arr(char *buf_for_arr);
char	**ft_arr_temp(t_map *map);
void	ft_move(t_data *data, char pos, int dir);
int		ft_open_map_file(char **argv);
void	ft_put_background(t_data *data);
void	ft_put_object(t_data *data, void *img);
void	ft_put_player(t_data *data);
void	ft_win(t_data *data);

#endif
