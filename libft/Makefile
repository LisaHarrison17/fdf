# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lharris <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/04 15:28:19 by lharris           #+#    #+#              #
#    Updated: 2018/08/13 12:22:18 by lharris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

HEADER	=	libft.h

COMP	=	gcc

FLAGS	=	-Wall -Werror -Wextra

SRC		=	ft_atoi.c \
			ft_bzero.c \
			ft_isdigit.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_memset.c \
			ft_strclr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strncpy.c \
			ft_strnew.c \
			ft_strsplit.c \
			ft_strsub.c \
			get_next_line.c

all:	$(NAME)

$(NAME):	
			@$(COMP) -c $(SRC) $(FLAGS)
			@ar rcs $(NAME) *.o
			@ranlib $(NAME)
			@echo "- LIBRARY COMPILED -"

%.o:	$(HEADER)

clean:
		@-rm -f *.o
		@echo "- files deleted -"

fclean:	clean
		@-rm -f *.a
		@echo "- library cleared -"

re:		fclean all

.PHONY:	all, clean, fclean, re