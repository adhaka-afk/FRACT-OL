# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 13:08:00 by adhaka            #+#    #+#              #
#    Updated: 2023/09/23 22:02:02 by adhaka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 			= fractol

CC				= cc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

SRCS			=	fractol.c \
					ft_atof.c \
					julia.c \
					mandelbrot.c \
					hook_and_zoom.c \
					error.c \
					utils.c \

OBJS			= $(SRCS:.c=.o)

MLX_DIR =		./MLX42/build
MLX_42 =		$(MLX_DIR)/libmlx42.a

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) -C $(MLX_DIR)
				$(CC) $(FLAGS) $(OBJS) $(MLX_42) -o $(NAME) -I MLX42/include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"

$(OBJS):		fractol.h

$(MLX_42):
				(cd MLX42 && cmake -B build)
				make -C $(MLX_DIR)

clean:
				$(RM) $(OBJS)

rmlib:
				$(RM) $(MLX_42)

fclean:			clean rmlib
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean  rmlib fclean re
