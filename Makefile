# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucien <lucien@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 11:25:50 by lucien            #+#    #+#              #
#    Updated: 2018/09/22 18:37:18 by lterrail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= push_swap
NAME2	= checker

SRC1	=	push_swap.c				\
			quick_sort_init.c		\
			shaker.c				\
			simple_case.c 			\
			get_data.c				\
			sort.c					\
			quick_sort.c			\
			list.c					\
			error.c					\
			ope/operator.c 			\
			ope/swap.c				\
			ope/push.c				\
			ope/rotate.c			\
			ope/reverse.c

SRC2	=	checker.c				\
			list.c 					\
			error.c		 			\
			get_data.c 				\
			sort.c 					\
			shaker.c 				\
			ope/swap.c				\
			ope/operator.c 			\
			ope/push.c 				\
			ope/reverse.c 			\
			ope/rotate.c

OBJ1		= $(addprefix ./obj/,$(SRC1:.c=.o))
OBJ2		= $(addprefix ./obj/,$(SRC2:.c=.o))

all: obj libft $(NAME1) $(NAME2)
	
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFTA	= ./libft/libft.a
LIBINCL = -I./libft/includes
LIBLINK	= -L./libft -lft

obj:
	@mkdir -p ./obj/
	@mkdir -p ./obj/ope/

./obj/%.o:./src/%.c
	@$(CC) $(CFLAGS) $(LIBINCL) -Iincludes -o $@ -c $<

libft: $(LIBFTA)

$(LIBFTA):
	@make -C ./libft

$(NAME2): $(OBJ2)
	@$(CC) -o $(NAME2) $(OBJ2) $(LIBLINK)

$(NAME1): $(OBJ1)
	@$(CC) -o $(NAME1) $(OBJ1) $(LIBLINK)


clean:
	@rm -rf ./obj/
	@make -C ./libft clean

fclean: clean
	@rm -rf $(NAME1)
	@rm -rf $(NAME2)
	@make -C ./libft fclean

re: fclean all
