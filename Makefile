# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 12:04:49 by hutzig            #+#    #+#              #
#    Updated: 2024/08/20 09:21:16 by hutzig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

DIR_LIBFT = ./lib/libft
DIR_SRC = ./sources

SOURCES = push_swap.c \
	data_processing.c \
	error_checking.c \
	error_handling.c \
	execute_operations.c \
	operations_push.c \
	operations_reverse.c \
	operations_rotate.c \
	operations_swap.c \
	pushing_a_to_b.c \
	stack_sorting.c \
	stack_sorting_check.c \
	stack_utils.c \

SRC = $(addprefix $(DIR_SRC)/,$(SOURCES))

OBJECTS = $(SRC:.c=.o)

HEADERS = -I ./includes -I $(DIR_LIBFT)

LIBFT = -L $(DIR_LIBFT) -lft

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(NAME): libft $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFT) $(HEADERS) -o $@

libft: 
	@make -C $(DIR_LIBFT)

$(DIR_SRC)/%.o: $(DIR_SRC)/%.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	@make -C $(DIR_LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(DIR_LIBFT) fclean

re: fclean all

.PHONY: all libft clean fclean re
