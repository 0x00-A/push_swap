# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aigounad <aigounad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 15:25:14 by aigounad          #+#    #+#              #
#    Updated: 2023/01/10 15:25:45 by aigounad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC  = ft_memset.c \
		ft_split.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_substr.c \
		get_next_line.c \
		ft_error.c

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
