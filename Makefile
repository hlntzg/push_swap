# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 12:04:49 by hutzig            #+#    #+#              #
#    Updated: 2024/08/15 09:54:24 by hutzig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

DIR_LIBFT = ./lib/libft
DIR_SRC = ./sources

SOURCES = data_processing.c \
	error_checking.c \
	error_handling.c \
	push_swap.c \
	stack_sorting.c \
	stack_sorting_check.c \
	stack_utils.c \
	operations_push.c \
	operations_swap.c \
	operations_reverse.c \
	operations_rotate.c  \

SRC = $(addprefix $(DIR_SRC)/,$(SOURCES))

OBJECTS = $(SRC:.c=.o)

HEADERS = -I ./include -I $(DIR_LIBFT)

INCLUDE = -L $(DIR_LIBFT) -lft

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): libft $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(INCLUDE) $(HEADERS) -o $@

libft: 
	@make -C $(DIR_LIBFT)

$(DIR_SRC)/%.o: $(DIR_LIBFT)/%.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	@make -C $(DIR_LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(DIR_LIBFT) fclean

re: fclean all

.PHONY: all libft clean fclean re
