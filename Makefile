# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 19:02:19 by ouaarabe          #+#    #+#              #
#    Updated: 2023/05/01 21:33:11 by ouaarabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_B = fractol_bonus

SRC	=	src/main.c\
		src/mandelbrot.c\
		src/julia.c\
		src/draw.c\
		src/tools.c\
		src/tool2.c\
		
SRC_B	=	bonus/src_b/main.c\
			bonus/src_b/mandelbrot.c\
			bonus/src_b/burning_ship.c\
			bonus/src_b/julia.c\
			bonus/src_b/draw.c\
			bonus/src_b/tools.c\
			bonus/src_b/tool2.c\

OBJ	=	${SRC:.c=.o}

OBJ_B	=	${SRC_B:.c=.o}


INC		=	inc/fractol.h
INC_B	=	bonus/inc_b/fractol.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Ofast #-fsanitize=address
RM			=	rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@ $(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $@ $(OBJ)

%.o: %.c
	@ $(CC) $(CFLAGS) -Ilmlx -c $< -o $@

clean:
	@ $(RM) $(OBJ) $(OBJ_B)

fclean: clean
	@ $(RM) $(NAME) $(NAME_B)

re: fclean all

bonus: ${NAME_B}

${NAME_B} : ${OBJ_B} ${INC_B}
	@ $(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $@ $(OBJ_B)

.PHONY: clean fclean re bonus
