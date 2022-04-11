# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zzirh <zzirh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 21:33:37 by zzirh             #+#    #+#              #
#    Updated: 2022/04/01 15:54:38 by zzirh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
PRINTF = f_Printf/libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_fcts.c
OBJ = ${SRC:%.c=%.o}
SRCBON = ft_fcts_bonus.c
OBJBON = ${SRCBON:%.c=%.o}

NAME = minitalk.a
NAMEBON = minitalk_bonus.a

.PHONY:all clean fclean re

all : ${NAME} server client 
bonus : ${NAMEBON} server_bonus client_bonus

${NAME}: ft_minitalk.h ${OBJ}
	make -C f_Printf
	ar -rc ${NAME} ${OBJ}

${NAMEBON}: ft_minitalk.h ${OBJBON}
	make -C f_Printf
	ar -rc ${NAMEBON} ${OBJBON}
	
client: ft_client.c
	${CC} ${FLAGS} ft_client.c -o client ${PRINTF} ${NAME}

server: ft_server.c
	${CC} ${FLAGS} ft_server.c -o server ${PRINTF} ${NAME}
	
client_bonus:ft_client_bonus.c
	${CC} ${FLAGS} ft_client_bonus.c -o client_bonus ${PRINTF} ${NAMEBON}

server_bonus:ft_server_bonus.c
	${CC} ${FLAGS} ft_server_bonus.c -o server_bonus ${PRINTF} ${NAMEBON}

clean:
	make fclean -C f_Printf
	rm -f $(OBJ)
	rm -f ${OBJBON}
fclean:clean
	rm -f ${NAME} ${OBJ}
	rm -f ${NAMEBON} ${OBJBON}
	rm server client server_bonus client_bonus
re: fclean all
