# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 01:04:10 by ouaarabe          #+#    #+#              #
#    Updated: 2023/04/11 23:12:20 by ouaarabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRACTOL		= fractol

SRC_C	=	mandatory/client.c
SRC_S	=	mandatory/server.c
SRC_CB	=	bonus/client_bonus.c
SRC_SB	=	bonus/server_bonus.c

OBJ_S	=	mandatory/server.o
OBJ_C	=	mandatory/client.o
OBJ_SB	=	bonus/server_bonus.o
OBJ_CB	=	bonus/client_bonus.o

INC		=	mandatory/minitalk.h
INC_B	=	bonus/minitalk_bonus.h

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -rf

all: $(UTILS) $(CLIENT) $(SERVER)

$(SERVER): $(OBJ_S) $(INC)
	@ $(CC) $(CFLAGS) $(UTILS) -o $@ $(OBJ_S)

$(CLIENT): $(OBJ_C) $(INC)
	@ $(CC) $(CFLAGS) $(UTILS) -o $@ $(OBJ_C)

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(UTILS):
	@ $(MAKE) -C $(UTILS_DIR)

clean:
	@ $(MAKE) clean -C $(UTILS_DIR)
	@ $(RM) $(OBJ_C) $(OBJ_S)
	@ $(RM) $(OBJ_CB) $(OBJ_SB)

fclean: clean
	@ $(MAKE) fclean -C $(UTILS_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@ $(RM) $(CLIENT_B) $(SERVER_B)

re: fclean all

bonus: $(UTILS) $(CLIENT_B) $(SERVER_B)

$(SERVER_B): $(OBJ_SB) $(INC_B)
	@ $(CC) $(CFLAGS) $(UTILS) -o $@ $(OBJ_SB)

$(CLIENT_B): $(OBJ_CB) $(INC_B)
	@ $(CC) $(CFLAGS) $(UTILS) -o $@ $(OBJ_CB)


.PHONY: clean fclean re bonus
