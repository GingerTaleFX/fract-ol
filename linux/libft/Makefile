# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 14:53:27 by kroselin          #+#    #+#              #
#    Updated: 2020/05/16 19:13:30 by ginger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
SOURCES = ft_lstmap.c ft_lstiter.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c ft_putnbr_fd.c ft_putendl_fd.c ft_itoa.c ft_putstr_fd.c ft_putendl.c \
        ft_putchar_fd.c ft_count_mass.c ft_strsplit.c ft_strtrim.c ft_strjoin.c ft_strsub.c ft_strnequ.c ft_strequ.c ft_strmapi.c ft_strmap.c ft_striteri.c \
        ft_striter.c ft_strclr.c ft_strdel.c ft_strnew.c ft_memdel.c ft_memalloc.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
        ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strcat.c ft_strchr.c ft_strcmp.c \
        ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnlen.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c \
        ft_toupper.c ft_cl.c get_next_line.c
OBJECTS = $(SOURCES:.c=.o)
HEADER = libft.h get_next_line.h
CC = gcc
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -I./ -c $<

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all