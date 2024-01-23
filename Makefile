# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 15:31:42 by yufonten          #+#    #+#              #
#    Updated: 2024/01/23 16:36:29 by yufonten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft.a
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

re: fclean all.

.PHONY:	all clean fclean re
