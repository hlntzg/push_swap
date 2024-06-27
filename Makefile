# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 12:04:49 by hutzig            #+#    #+#              #
#    Updated: 2024/06/27 08:46:40 by hutzig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = .c

OBJECTS = $(SOURCES:.c=.o)

HEADER = push_swap.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rcs

all: $(NAME)

# compiler

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
