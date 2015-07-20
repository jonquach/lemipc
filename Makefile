##
## Makefile for  in /home/quach_a/rendu/PSU_2014_lemipc
## 
## Made by Jonathan Quach
## Login  <jonathan.quach@epitech.eu>
## 
## Started on  Sun Mar  8 20:44:44 2015 Jonathan Quach
## Last update Sun Mar  8 22:39:24 2015 Daniel Han
##

SRCS =  main.c \
	shm.c \
	sem.c \
	process.c \
	player.c \
	game.c

OBJS = $(SRCS:.c=.o)

NAME = lemipc

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clan fclean re

