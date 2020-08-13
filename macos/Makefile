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
        draw.c \
	kb_utils.c \
	mouse_control.c \
	zoom.c

CC = gcc
FLAGS = -Wall -Wextra -Werror -Wdeprecated-declarations
OBJS = $(SRCS:.c=.o)
INCLUDES = -I./libft/ \
	-I./minilibx_macos/

LIBSINC = -L./libft/ \
	-L./minilibx_macos/

LIBFTPATH = ./libft/
MINILIBXPATH = ./minilibx_macos/

LIBSNAME = libft.a \
	libmlx.a

HEADERS = fractol.h \
		macos_keys.h

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

%.o: %.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTPATH)
	@echo "\n$(LIBFTPATH) $(GREEN) libft is done $(RESET)"
	$(MAKE) -C $(MINILIBXPATH)
	@echo "\n $(GREEN)MINILIB files were created$(RESET)"
	$(CC) -o $(NAME) $(OBJS) $(LIBSINC) -lmlx -lm -lft -framework OpenGL -framework AppKit -Wdeprecated-declarations

clean:
	$(MAKE) fclean -C $(LIBFTPATH)
	@echo "\n $(RED) LIBFT is cleared $(RESET)"
	$(MAKE) clean -C $(MINILIBXPATH)
	@echo "\n $(RED) MINILIB is cleared $(RESET)"
	/bin/rm -f $(OBJS)
	@echo "$(RED) OBJ-s are cleared $(RESET)"

fclean: clean
	/bin/rm -f $(NAME)
	@echo "$(RED) $(NAME) was killed $(RESET)"

re: fclean all

.PHONY: clean fclean re all

