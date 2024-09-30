# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msisto <msisto@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 15:05:58 by msisto            #+#    #+#              #
#    Updated: 2024/09/30 14:31:45 by msisto           ###   ########.fr        #
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

test-i-leaks-m: re
	@clear
	@echo ===== Mandatori =====
	-valgrind ./push_swap
	@echo
	-valgrind ./push_swap ""
	@echo
	-valgrind ./push_swap ''
	@echo
	-valgrind ./push_swap "   "
	@echo
	-valgrind ./push_swap 42 42
	@echo
	-valgrind ./push_swap Voglio mangiare il tuo pancreas
	@echo
	-valgrind ./push_swap "Voglio mangiare il tuo pancreas"
	@echo
	-valgrind ./push_swap "Voglio mangiare il tuo pancreas" 42
	@echo
	-valgrind ./push_swap "42" Voglio mangiare il tuo pancreas
	@echo
	-valgrind ./push_swap "++42"
	@echo
	-valgrind ./push_swap "--42"
	@echo
	-valgrind ./push_swap 1 "2" 3
	@echo
	-valgrind ./push_swap 1 "2 3" 4
	@echo
	-valgrind ./push_swap 1 "2 3" 2
	@echo
	-valgrind ./push_swap "''"
	@echo
	-valgrind ./push_swap '""'
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-i-leaks-b: bonus
	@clear
	@echo ===== Bonus =====
	-valgrind ./checker
	@echo
	-valgrind ./checker ""
	@echo
	-valgrind ./checker ''
	@echo
	-valgrind ./checker "   "
	@echo
	-valgrind ./checker 42 42
	@echo
	-valgrind ./checker Voglio mangiare il tuo pancreas
	@echo
	-valgrind ./checker "Voglio mangiare il tuo pancreas"
	@echo
	-valgrind ./checker "Voglio mangiare il tuo pancreas" 42
	@echo
	-valgrind ./checker "42" Voglio mangiare il tuo pancreas
	@echo
	-valgrind ./checker "++42"
	@echo
	-valgrind ./checker "--42"
	@echo
	-valgrind ./checker 1 "2" 3
	@echo
	-valgrind ./checker 1 "2 3" 4
	@echo
	-valgrind ./checker 1 "2 3" 2
	@echo
	-valgrind ./checker "''"
	@echo
	-valgrind ./checker '""'
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-i-nleaks-m: re
	@clear
	@echo ===== Mandatori =====
	-./push_swap
	@echo
	-./push_swap ""
	@echo
	-./push_swap ''
	@echo
	-./push_swap "   "
	@echo
	-./push_swap 42 42
	@echo
	-./push_swap Voglio mangiare il tuo pancreas
	@echo
	-./push_swap "Voglio mangiare il tuo pancreas"
	@echo
	-./push_swap "Voglio mangiare il tuo pancreas" 42
	@echo
	-./push_swap "42" Voglio mangiare il tuo pancreas
	@echo
	-./push_swap "++42"
	@echo
	-./push_swap "--42"
	@echo
	-./push_swap 1 "2" 3
	@echo
	-./push_swap 1 "2 3" 4
	@echo
	-./push_swap 1 "2 3" 2
	@echo
	-./push_swap "''"
	@echo
	-./push_swap '""'
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-i-nleaks-b: bonus
	@clear
	@echo ===== Bonus =====
	-./checker
	@echo
	-./checker ""
	@echo
	-./checker ''
	@echo
	-./checker "   "
	@echo
	-./checker 42 42
	@echo
	-./checker Voglio mangiare il tuo pancreas
	@echo
	-./checker "Voglio mangiare il tuo pancreas"
	@echo
	-./checker "Voglio mangiare il tuo pancreas" 42
	@echo
	-./checker "42" Voglio mangiare il tuo pancreas
	@echo
	-./checker "++42"
	@echo
	-./checker "--42"
	@echo
	-./checker 1 "2" 3
	@echo
	-./checker 1 "2 3" 4
	@echo
	-./checker 1 "2 3" 2
	@echo
	-./checker "''"
	@echo
	-./checker '""'
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

ARG_TESTER=$$(cat ./n.txt)

test-f100-leaks-m: re
	@clear
	sh ./Assets_tester/Push_Swap/n_gen_100.sh
	@echo "Lista ordinata: "
	@-valgrind ./$(NAME) $(ARG_TESTER) | ./Assets_tester/Push_Swap/checker $(ARG_TESTER)
	@echo "N. mosse: "
	@-valgrind ./$(NAME) $(ARG_TESTER) | wc -l
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-f500-leaks-m: re
	@clear
	sh ./Assets_tester/Push_Swap/n_gen_500.sh
	@echo "Lista ordinata: "
	@-valgrind ./$(NAME) $(ARG_TESTER) | ./Assets_tester/Push_Swap/checker $(ARG_TESTER)
	@echo "N. mosse: "
	@-valgrind ./$(NAME) $(ARG_TESTER) | wc -l
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-f100-nleaks-m: re
	@clear
	sh ./Assets_tester/Push_Swap/n_gen_100.sh
	@echo "Lista ordinata: "
	@-./$(NAME) $(ARG_TESTER) | ./Assets_tester/Push_Swap/checker $(ARG_TESTER)
	@echo "N. mosse: "
	@-./$(NAME) $(ARG_TESTER) | wc -l
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-f500-nleaks-m: re
	@clear
	sh ./Assets_tester/Push_Swap/n_gen_500.sh
	@echo "Lista ordinata: "
	@-./$(NAME) $(ARG_TESTER) | ./Assets_tester/Push_Swap/checker $(ARG_TESTER)
	@echo "N. mosse: "
	@-./$(NAME) $(ARG_TESTER) | wc -l
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-norm:
	@echo Errori di norma:
	@norminette *.c *.h | grep Error! | wc -l
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

