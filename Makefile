# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aigounad <aigounad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 00:09:57 by aigounad          #+#    #+#              #
#    Updated: 2023/01/10 16:21:40 by aigounad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap
NAME_BONUS = checker
HEADER = push_swap.h
LIB_DIR = ./libft
LIB_BINARY = ./libft/libft.a
LIBFT = ft

SRC = main.c best_move.c check_stack.c final_sort.c lis_algorithm.c operations_1.c \
		operations_2.c operations_3.c push_swap.c push_swap_utils.c sort_3_and_5.c

SRC_BONUS = checker.c check_stack.c checker_utils.c operations_1.c operations_2.c \
			operations_3.c push_swap_utils.c

OBJ = $(SRC:c=o)
OBJ_BONUS = $(SRC_BONUS:c=o)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(LIB_BINARY)  $(OBJ) 
	$(CC) $(OBJ) -L$(LIB_DIR) -l$(LIBFT) -o $(NAME)

FORCE :

$(LIB_BINARY) : FORCE
	@make -C $(LIB_DIR)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(LIB_BINARY) $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -L$(LIB_DIR) -l$(LIBFT) -o $(NAME_BONUS)

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	make clean -C $(LIB_DIR)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	make fclean -C $(LIB_DIR)

re : fclean all
