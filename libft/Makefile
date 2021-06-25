# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichougra <ichougra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 14:33:30 by ichougra          #+#    #+#              #
#    Updated: 2021/05/28 05:11:43 by ichougra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I includes/

NAME	=	libft.a

HEADER	= libft.h

SRCS	=	ft_atoi.c\
			ft_strcpy.c\
			ft_strcat.c\
			ft_putstr.c\
			ft_strcmp.c\
			ft_memdel.c\
			ft_putendl.c\
			ft_skip_spacenl.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_del.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_skip_space.c\
			ft_strcpyv.c\
			ft_strisnum.c\

BNS		=	ft_lstnew_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstmap_bonus.c\

OBJ		=	$(SRCS:.c=.o) 

OBJ2	=	$(BNS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)


%.o : %.c
	@printf "\033[0;33mGenerating libft objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@
	
bonus: $(OBJ) $(OBJ2)
	@ar rc $(CFLAGS) $(NAME) $(OBJ) $(OBJ2)

clean:
	@rm -f $(OBJ) $(OBJ2)


fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all fclean clean re

