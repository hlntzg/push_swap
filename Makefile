# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 12:04:49 by hutzig            #+#    #+#              #
#    Updated: 2024/07/02 15:33:01 by hutzig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = data_processing.c \
	error_checking.c \
	error_handling.c \
	push_swap.c \
	stack_sorting.c \
	stack_sorting_check.c \

OBJECTS = $(SOURCES:.c=.o)

INCLUDE = -L ./libft -lft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(INCLUDE)

clean:
	$(RM) $(OBJECTS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
