# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/08 13:45:25 by ozhyhadl          #+#    #+#              #
#    Updated: 2019/03/21 11:16:25 by ozhyhadl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol

SRC     = src/main.c \
			src/ft_draw.c \
			src/ft_fractal.c \
			src/ft_help_win.c\
			src/ft_init.c \
			src/ft_key_2.c \
			src/ft_key.c 

OBJ     = $(SRC:.c=.o)
LIBFT   = libft/
HDR  = include/fractol.h 
CC      = /usr/bin/gcc
CFLAGS  = -Wall -Wextra -Werror
FMLX    = -framework OpenGL -framework AppKit -lmlx
DEL      = /bin/rm -f

all:        $(NAME)

$(NAME):    $(OBJ) $(LIBFT)
	@make -C $(LIBFT)	
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I $(HDR) -L $(LIBFT)  -lft $(FMLX)
	@echo "\x1b[32m -->> Compilation Success: Fractol"

%.o : %.c $(HDR) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ -c $< -I .

clean:
	@make fclean -C $(LIBFT)
	@$(DEL) $(OBJ)
	@echo "\x1b[32m -->> Object files are deleted"

fclean:     clean
	@make -C $(LIBFT) fclean
	@$(DEL) $(NAME)
	@echo "\x1b[32m -->> Fractol was deleted"


re:     fclean all

.PHONY:     re all clean fclean



	