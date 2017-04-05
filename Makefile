# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 22:13:19 by ahamouda          #+#    #+#              #
#    Updated: 2016/02/14 22:03:08 by ahamouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = clang
rm = rm -f
CFLAGS = -Wall -Werror -Wextra
DEBUGFLAG = -g3 -fsanitize=address
INCLUDES = ./h/
OBJ = $(SRC:.c=.o)
SRC = fdf.c \
	  check_error.c \
	  key_hook.c \
	  draw_map.c \
	  draw2.c
HEADER = fdf.h

.SILENT:

all : $(NAME)

$(NAME) : $(OBJ)
		@Make -C ./libft/
		@Make -C ./libmx2/
		$(CC) -o $(NAME) $(SRC) $(CFLAGS) -L ./libft/ -L ./libmx2/ -lft -lmlx \
			-framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES)

clean:
	@Make -C ./libft/ clean
	$(RM) $(OBJ)

fclean: clean
	@Make -C ./libft/ fclean
	@Make -C ./libmx2/ clean
	$(RM) $(NAME)

re: fclean all

norme:
	norminette $(SRC) $(HEADER)

function:
	nm -u $(NAME)

.PHONY: re fclean clean all norme function
