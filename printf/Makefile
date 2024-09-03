# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msisto <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 13:14:00 by msisto            #+#    #+#              #
#    Updated: 2024/02/13 14:21:52 by msisto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = \
	  ft_printf.c ft_calloc.c ft_outputs.c ft_extra_outputs.c 

OUT = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

$(NAME) : $(OUT)
	ar rsc $(NAME) $(OUT)

all: $(NAME)

clean:
	rm -f $(OUT)

fclean: clean
	rm -f $(NAME)

re: fclean all
