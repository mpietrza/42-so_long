# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 14:21:04 by mpietrza          #+#    #+#              #
#    Updated: 2023/12/13 17:46:30 by mpietrza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
DIR_LIBFT	= ./libft/
DIR_MLX		= ./mlx/
DIR_SRCS	= ./srcs/
DIR_OBJS	= ./objs/
DIR_INCL	= ./include/
LIBFT		= $(DIR_LIBFT)libft.a
LIB_MLX		= $(DIR_MLX)libmlx.a
INCLUDE		= so_long.h
FLAGS_MLX	= -Lmlx -lmlx -framework OpenGL -framework AppKit
CC			= cc
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address -g
RM			= rm -f

#COLORS
DEF_COLOR = "\033[39m"
GRAY = "\033[30m"
R = "\033[31m"
G = "\033[32m"
Y = "\033[33m"
B = "\033[34m"
M = "\033[35m"
C = "\033[36m"
W = "\033[37m"

#SOURCES

SRC			= cleanup.c \
			  exit.c \
			  flood_fill.c \
			  initialize.c \
			  init_map.c \
			  map_check_path.c \
			  map_check_scan.c \
			  map_find_start_pos.c \
			  map_parse.c \
			  move.c \
			  put_textures.c \
			  so_long.c \
			  utils.c
			 
SRCS		= $(addprefix $(DIR_SRCS), $(SRC))

OBJS		= $(addprefix $(DIR_OBJS), $(SRC:.c=.o))

DEPS		= $(OBJS:.o=.d)

all:	$(DIR_OBJS) $(NAME)

-include $(DEPS)

$(DIR_OBJS)%.o : $(DIR_SRCS)%.c
	@echo $(B)Compiling [$<]... $(DEF_COLOR)
	$(CC) $(CFLAGS) -MMD -MP -Imlx -c -o $@ $<

utils:
	@echo $(B)
	make -C $(DIR_MLX)
	make -C $(DIR_LIBFT)
	@echo $(DEF_COLOR)

$(DIR_OBJS):
	@echo Creating directory: $(DIR_OBJS)
	mkdir -p $(DIR_OBJS)

$(NAME): $(OBJS) Makefile
	$(MAKE) utils
	$(CC) $(CFLAGS) $(OBJS) $(FLAGS_MLX) $(LIB_MLX) $(LIBFT) -o $(NAME)
	@echo $(G)So_long compiled successfully! $(DEF_COLOR)

clean:
	make -C $(DIR_LIBFT) clean 
	make -C $(DIR_MLX) clean
	$(RM) -rf $(OBJS) $(DEPS) $(DIR_OBJS)
	@echo $(GRAY)So_long object files erased succesfully! $(DEF_COLOR)

fclean: clean
	make -C $(DIR_LIBFT) fclean
	$(RM) $(NAME)
	@echo $(GRAY)So_long executable files erased succesfully! $(DEF_COLOR)
	
re:		fclean all
	@echo $(G)Erased and recompiled every file of so_long successfully!	$(DEF_COLOR)

debug:
	@echo "Source files: $(SRCS)"
	@echo "Object files: $(OBJS)"
	@echo "Dependency files: $(DEPS)"

.PHONY: all clean fclean re debug
