# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 15:31:42 by yufonten          #+#    #+#              #
#    Updated: 2024/02/21 13:29:14 by yufonten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft.a
BONUS = checker
SRC_FILES = push_swap.c\
			check_args.c\
			error_situation.c\
			init_stack.c\
			push.c\
			swap.c\
			rotate.c\
			reverse_rotate.c\
			stack_utils.c\
			sorted_three.c\
			sorted_algorithm.c\
			init_nodes_a.c\
			init_nodes_b.c\
			
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME):
		@$(MAKE) -C libft
		@$(CC) $(CFLAGS) $(SRC_FILES) libft/$(LIBFT) -o $(NAME)
		@echo  Correctly generated push_swap

clean:
		@$(MAKE) clean -C ./libft/

fclean: clean
		@$(MAKE) fclean -C ./libft/
		@$(RM) $(LIBFT) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
