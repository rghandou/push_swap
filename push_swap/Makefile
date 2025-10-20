# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 10:31:16 by rghandou          #+#    #+#              #
#    Updated: 2025/09/22 08:45:08 by rghandou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = push_swap.a

CFLAG = -Wall -Wextra -Werror

SRC = fct_helper.c \
	  ft_function_a.c \
	  ft_libft.c \
	  ft_input.c \

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