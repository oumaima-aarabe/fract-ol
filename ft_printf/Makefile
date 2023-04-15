# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 00:40:13 by ouaarabe          #+#    #+#              #
#    Updated: 2022/11/16 11:14:01 by ouaarabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printnum.c ft_strlen.c ft_printchar.c ft_printstr.c\
ft_ln.c ft_printformat.c
 
CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

RM = rm -rf

NAME = libftprintf.a

%.o : %.c ft_printf.h 
	$(CC) -c $(CFLAGS) $< -o $@

${NAME} : ${OBJS}
	ar -rcs $@ ${OBJS}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : fclean clean re