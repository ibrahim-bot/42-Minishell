# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 16:30:43 by ichougra          #+#    #+#              #
#    Updated: 2021/06/25 19:28:15 by ichougra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -I includes/ -I libft/includes/

NAME = minishell

LIBFT = -L libft -lft

HEADER = minishell.h

SRC_PATH		=	srcs

SRCS_NAME		= 	bin.c builtin.c cd.c echo.c env.c env2.c exec.c exit.c\
					expan.c expan2.c export.c fd.c free.c get_env.c line.c\
					minishell.c parsing.c pwd.c redir.c shlvl.c signal.c print.c\
					sort_env.c token.c tokens.c type.c unset.c error.c ret.c ninput.c\

SRC = $(addprefix $(SRC_PATH)/,$(SRCS_NAME))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@make -C libft/
	@echo "\n\n\033[0;32mCompiling minishell..."
	@$(CC) -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[0;31mCleaning libft..."
	@make clean -C libft/
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31mCleaning libft..."
	@make fclean -C libft/
	@echo "\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

norm:
	norminette $(SRC) includes/$(HEADER)

.PHONY: clean fclean re norm
