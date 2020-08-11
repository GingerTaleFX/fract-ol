# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ginger <ginger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/22 13:50:30 by ginger            #+#    #+#              #
#    Updated: 2020/08/07 14:07:17 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c \
        init.c \
        draw.c

CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
INCLUDES = -I./libft/ \
	-I./minilibx/

LIBSINC = -L./libft/ \
	-L./minilibx/

LIBFTPATH = ./libft/
MINILIBXPATH = ./minilibx/

LIBSNAME = libft.a \
	libmlx.a

HEADERS = fractol.h \
            linux_keys.h

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFTPATH)
	@$(MAKE) -C $(MINILIBXPATH)
	@$(CC) -o $(NAME) $(OBJS) $(LIBSINC) -lft -lmlx -lOpenGL -lX11 -lm -lXext

clean:
	$(MAKE) fclean -C $(LIBFTPATH)
	$(MAKE) clean -C $(MINILIBXPATH)
	/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
