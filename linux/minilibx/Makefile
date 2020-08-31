##
## Makefile for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 15:56:43 2004 Olivier Crouzet
## Last update Tue May 15 15:44:41 2007 Olivier Crouzet
##

## Please use configure script

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
RESET = \033[0m
UP = "\033[A"
CUT = "\033[K"

all	: do_configure

do_configure	:
	./configure

clean	:
	./configure clean
	@echo "$(RED)Cleaning MLX object files $(RED)[Done]$(RESET)"


re	: clean all

install:
	@$(MAKE) -f Makefile.gen $@
