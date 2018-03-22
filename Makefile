# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/06 16:29:53 by bbardocz          #+#    #+#              #
#    Updated: 2018/03/16 15:41:47 by bbardocz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c mandelbrot.c
OBJ = main.o mandelbrot.o

CC = cc

LIBFTD = libft
LIBMLX = /usr/local/include
LDFLAGS = -Wall -Wextra -Werror -I$(LIBFTD) -I$(LIBMLX) -g
LDLIBS = -L $(LIBFTD) -lft -L /usr/local/lib/ -lmlx -framework Opengl \
		 -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTD)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	make -C $(LIBFTD) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTD) fclean

re: fclean all
