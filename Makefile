# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 17:09:30 by lquehec           #+#    #+#              #
#    Updated: 2023/12/17 13:48:23 by lquehec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################
##  PRINT COLORS  ##
####################

RESET		= \033[0m
BOLD		= \033[1m
UNDER		= \033[4m
REV			= \033[7m
DEF_COLOR	= \033[0;39m
BLACK		= \033[0;30m
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
GRAY		= \033[0;37m
DELETE		= \033[2K\r

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
			@printf "\n${BLUE}%-44s${RESET} ${GREEN}%s${RESET}\n" "Compiling project" "done"

all: 		$(NAME)

clean:
			@$(RM) $(OBJS) $(MAIN_OBJ)
			@$(MAKE_LIBFT) clean
			@printf "${BLUE}%-44s${RESET} ${GREEN}%s${RESET}\n" "Cleaning" "done"

fclean:		clean
			@$(RM) $(NAME) $(MAIN_OBJ) $(OUTPUT_CHECKER)
			@$(MAKE_LIBFT) fclean
			@printf "${BLUE}%-44s${RESET} ${GREEN}%s${RESET}\n" "File cleaning" "done"

re:			fclean all

checker:	all
			@$(CC) $(CFLAGS) -I $(HEADER_DIR) $(CHECKER_PATH) $(OBJS) $(LIBFT_PATH) -o $(OUTPUT_CHECKER)
			@printf "\n${BLUE}%-44s${RESET} ${GREEN}%s${RESET}\n" "Compiling checker" "done"

.PHONY: all clean fclean re checker norm