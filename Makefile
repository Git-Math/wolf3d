#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/30 18:48:25 by mnguyen           #+#    #+#              #
#    Updated: 2015/06/08 18:58:23 by mnguyen          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror

ARG = -L/usr/X11/lib -Lminilibx_macos -framework OpenGL -framework AppKit

FILES = ./srcs/wolf3d.c ./srcs/minimap.c ./srcs/moove.c ./srcs/init.c

LIBNAME = ./minilibx_macos/libmlx.a ./libft/libft.a ./srcs/algo.c

all : $(NAME)

$(NAME) : $(FILES)
	make -C minilibx_macos
	make -C libft
	gcc $(FLAGS) $(ARG) $(FILES) -o $(NAME) $(LIBNAME)

clean :
	make -C minilibx_macos clean
	make -C libft clean

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all