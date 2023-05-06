# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 19:02:19 by ouaarabe          #+#    #+#              #
#    Updated: 2023/05/06 00:08:41 by ouaarabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_B = fractol_bonus

SRC	=	mandatory/src/main.c\
		mandatory/src/mandelbrot.c\
		mandatory/src/julia.c\
		mandatory/src/draw.c\
		mandatory/src/tools.c\
		mandatory/src/tool2.c\
		mandatory/src/tools3.c\
		mandatory/src/help_msg.c\
		
SRC_B	=	bonus/src_b/main.c\
			bonus/src_b/mandelbrot.c\
			bonus/src_b/burning_ship.c\
			bonus/src_b/julia.c\
			bonus/src_b/draw.c\
			bonus/src_b/tools.c\
			bonus/src_b/tool2.c\
			bonus/src_b/tools3.c\
			bonus/src_b/tools4.c\
			bonus/src_b/help_msg.c\

OBJ	=	${SRC:.c=.o}

OBJ_B	=	${SRC_B:.c=.o}


INC		=	mandatory/inc/fractol.h
INC_B	=	bonus/inc_b/fractol.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Ofast #-fsanitize=address
RM			=	rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@ $(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $@ $(OBJ)

%.o: %.c $(INC)
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
