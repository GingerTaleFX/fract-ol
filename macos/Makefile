NAME = fractol

### COMPILATION ###

CC = gcc
FLAGS = -Wall -Wextra -Werror

### INCLUDES ###

S_DIR = source
H_DIR = include
LIBFT = ../libft
MLX = minilibx_macos

### SOURCE FILES ###
SRCS = main.c \
        init.c \
        draw.c \
	kb_utils.c \
	mouse_control.c \
	zoom.c \
	fractols.c \
	utils.c

### OBJECTS ###

OBJS = $(addprefix $(S_DIR)/, $(SRCS:.c=.o))

### HEADERS ###

H_FILES = errors.h \
          fractol.h \
          macos_keys.h

HEADERS = $(addprefix $(H_DIR)/, $(H_FILES))

### COLORS ###

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
CYAN = \033[1;36m
WHITE = \033[1;37m
RESET = \033[0m

### RULES ###

all: lib tmp $(NAME)

lib:
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C $(LIBFT)
	@make -C $(MLX)
	@echo 	"$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -L $(LIBFT) -L $(MLX) -o $@ $^ -lmlx -lm -lft -framework OpenGL -framework AppKit
	@echo "$(GREEN)Project successfully compiled$(RESET)"

%.o: %.c $(HEADERS)
	@$(CC) $(FLAGS) -o $@ -c $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(RESET)"

clean:
	@echo "$(GREEN)Supressing libraries files$(RESET)"
	@$(MAKE) fclean -C $(LIBFT)
	@$(MAKE) clean -C $(MLX)
	@/bin/rm -f $(OBJS)

fclean: clean
	@echo "$(GREEN)Supressing libraries files$(RESET)"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
