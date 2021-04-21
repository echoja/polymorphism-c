# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 17:17:01 by taehokim          #+#    #+#              #
#    Updated: 2021/04/21 21:52:02 by taehokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = poly

SOURCES = \
	src/bag.c \
	src/main.c \
	src/memory.c \
	src/objs.c

OBJECTS = $(SOURCES:.c=.o)

RM = rm -f
INC_DIR = -I./src -I/usr/include -I/usr/local/include
FLAGS = -Wall -Wextra -Werror -g

CC = gcc

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $^ -o $@

$(OBJECTS): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJECTS)

re: fclean all

.PHONY: all clean fclean re .c.o
