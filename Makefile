# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 11:16:20 by edmartin          #+#    #+#              #
#    Updated: 2021/11/22 11:23:34 by edmartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRC_A		=	sources/push_swap.c sources/actions.c \
				sources/parse_utils.c sources/stack_functions.c \
				sources/sort.c sources/sort_utils.c sources/sort_large.c \
				sources/actions_utils.c

LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

INC		=	-Iincludes -I$(LIBFT_DIR)

CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
CLIB	=	ar -rc
RM		=	rm -f

GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

ifeq ($(DEBUG), 1)
	D_FLAG	=	-g
endif

ifeq ($(SANITIZE), 1)
	D_FLAG	=	-fsanitize=address -g
endif

mandatory:	$(NAME)

$(NAME):
	@ $(MAKE) bonus DEBUG=$(DEBUG) -C ./libft
	@ $(CC) $(CFLAG) $(D_FLAG) $(SRC_A) $(INC) $(LIBFT) -o $(NAME)
	@printf "$(_SUCCESS) push_swap ready.\n"

all:		$(NAME)

clean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)

fclean:
	@ $(RM) $(NAME)
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@printf "$(_INFO) push_swap and checker.\n"

re: fclean all

PHONY: all clean fclean re mandatory
