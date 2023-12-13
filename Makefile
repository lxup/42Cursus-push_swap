# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 17:09:30 by lquehec           #+#    #+#              #
#    Updated: 2023/12/13 20:45:22 by lquehec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
END=$'\x1b[0m'
BOLD=$'\x1b[1m'
UNDER=$'\x1b[4m'
REV=$'\x1b[7m'
GREY=$'\x1b[30m'
RED=$'\x1b[31m'
GREEN=$'\x1b[32m'
YELLOW=$'\x1b[33m'
BLUE=$'\x1b[34m'
PURPLE=$'\x1b[35m'
CYAN=$'\x1b[36m'
WHITE=$'\x1b[37m'

OS 			:= $(shell uname)
SRCS_DIR	= ./src/
HEADER_DIR	= ./includes/

SRCS 		= $(addprefix $(SRCS_DIR),\
				init.c \
				exit.c \
				error.c \
				parsing.c \
				is.c \
				print.c \
				sorting.c \
				sorting_complex.c \
				sorting_init.c \
				sorting_utils.c \
				utils.c \
				free.c \
				moves/ft_swap.c \
				moves/ft_rotate.c \
				moves/ft_rrotate.c \
				moves/ft_push.c \
				clst/ft_clstadd_back.c \
				clst/ft_clstadd_front.c \
				clst/ft_clstlast.c \
				clst/ft_clstnew.c \
				clst/ft_clstdelfirst.c \
				clst/ft_clstfree.c \
				clst/ft_clstfree_node.c )
				
OBJS 		= $(SRCS:.c=.o)

MAIN_SRC	= $(addprefix $(SRCS_DIR), main.c)
MAIN_OBJ	= $(MAIN_SRC:.c=.o)

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

# LIBFT
LIBFT_DIR	= ./libft
MAKE_LIBFT	= make -s -C $(LIBFT_DIR)
LIBFT_PATH	= $(LIBFT_DIR)/libft.a

# CHECKER
CHECKER_DIR		= ./checkers
CHECKER_PATH	= $(CHECKER_DIR)/checker.c
OUTPUT_CHECKER	= $(CHECKER_DIR)/checker

NAME 		= push_swap

.c.o:
			@/bin/echo -n .
			@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(MAIN_OBJ)
			@$(MAKE_LIBFT) all bonus
			@$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJ) $(LIBFT_PATH) -o $(NAME)
			@echo "\n${GREEN}> push_swap was successfuly compiled 🎉${END}"

all: 		$(NAME)

clean:
			@$(RM) $(OBJS) $(MAIN_OBJ)
			@$(MAKE_LIBFT) clean
			@echo "${YELLOW}> All objects files of so_long have been deleted ❌${END}"

fclean:		clean
			@$(RM) $(NAME) $(MAIN_OBJ) $(OUTPUT_CHECKER)
			@$(MAKE_LIBFT) fclean
			@echo "${YELLOW}> Cleaning of so_long has been done ❌${END}"

re:			fclean all

checker:	all
			@$(CC) $(CFLAGS) -I $(HEADER_DIR) $(CHECKER_PATH) $(OBJS) $(LIBFT_PATH) -o $(OUTPUT_CHECKER)
			@echo "\n${GREEN}> checker was successfuly compiled 🎉${END}"

.PHONY: all clean fclean re checker