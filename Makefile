# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 04:52:36 by leegichan         #+#    #+#              #
#    Updated: 2023/07/27 16:48:10 by gichlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC= 	main.c \
		monitor.c \
		parsing.c \
		philo.c \
		malloc_phil_arr.c \
		thread_create.c \
		thread_finish.c \
		time.c \
		util_libft.c \
		util_ft_strncmp.c \
		print.c \
		thread_check.c \

OBJ=$(SRC:%.c=%.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: 
	make fclean 
	make all
