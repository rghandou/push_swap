# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 10:31:16 by rghandou          #+#    #+#              #
#    Updated: 2025/10/22 10:29:37 by rghandou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = push_swap.a

CFLAG = -Wall -Wextra -Werror

SRC = fct_helper.c \
	  ft_function_a.c \
	  ft_input.c \
	  ft_function_b.c \
	  ft_function.c \
	  ft_parsing.c \
	  ft_algorithm.c \
	  ft_utils.c

OBJ = $(SRC:.c=.o)

RM = rm -f
AR = ar rc
RN = ranlib

%.o: %.cc
	$(CC) $(CFLAG) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
			$(AR) $(NAME) $(OBJ)
			$(RN)	$(NAME)

all: $(NAME)

clean: 
			$(RM) $(OBJ)

fclean: clean
			$(RM) $(NAME)

re: fclean	all

.PHONY: all, clean,  fclean, re
