# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msisto <msisto@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 15:05:58 by msisto            #+#    #+#              #
#    Updated: 2024/06/18 12:24:02 by msisto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PRINTF = printf/libftprintf.a

SRC = main.c argc_check.c arg_splitter.c ft_split.c moves.c moves2.c moves3.c \
	sorting.c sorting1.c utils.c utils2.c a_to_b_solver.c b_to_a_solver.c \
	if_three.c ft_rotate.c ft_apply_moves.c ft_apply_moves1.c

OUT = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

%.o%.c:
	${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

$(NAME) : $(OUT)
	@ make -C printf/
	$(CC) $(FLAGS) $(OUT) -o $(NAME) $(PRINTF)

all: $(NAME)

clean:
	@ make clean -C printf/
	rm -f $(OUT)

fclean: clean
	@ make fclean -C printf/
	rm -f $(NAME)

re: fclean all
	@ make re -C printf/

git:
	make fclean
	git add .
	git commit -m "update"
	git push
