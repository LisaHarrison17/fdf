NAME	=	fdf.a

HEADER	=	fdf.h

COMP	=	gcc

FLAGS	=	-Wall -Werror -Wextra

LIB_DIR = 	libft/

SRC 	= 	draw_map.c \
			read_file.c

# LIBFT 	= 	$(addprefix $(LIB_DIR), libft.a)

all:		$(NAME)

$(NAME):
			@make -C ./libft/
			@$(COMP) -c $(SRC) $(FLAGS)
			@ar rcs $(NAME) *.o
			@ranlib $(NAME)
			@$(COMP) -o fdf fdf.c $(NAME) -lmlx -framework OpenGL -framework AppKit -L ./libft/ -lft
			@echo "- LIBRARY COMPILED -"

%.o:		$(HEADER)

reall:
			@make libft/
			@make clean libft/

rc:
			@make re
			@make clean

clean:
			@/bin/rm -rf *.o
			@/bin/rm -rf ./libft/*.o
			@echo "- files deleted -"

fclean: 	clean
			@/bin/rm -rf $(NAME)
			@/bin/rm -rf ./libft/*.a
			@echo "- library cleared -"

re: fclean all

.PHONY: $(NAME), all, clean, fclean, re