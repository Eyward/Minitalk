# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zzirh <zzirh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 21:33:37 by zzirh             #+#    #+#              #
#    Updated: 2022/03/29 21:51:10 by zzirh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
PRINTF = f_Printf/libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_fcts.c
OBJ = ${SRC:%.c=%.o}

NAME = minitalk.a

all : ${NAME} server client 


${NAME}: ft_minitalk.h ${OBJ}
	make -C f_Printf
	ar -rc ${NAME} ${OBJ}


client: ft_client.c
	${CC} ${FLAGS} ft_client.c -o client ${PRINTF} ${NAME}

server: ft_server.c
	${CC} ${FLAGS} ft_server.c -o server ${PRINTF} ${NAME}

clean:
	make fclean -C f_Printf
	rm -f $(OBJ)
	
fclean:clean
	rm -f ${NAME} ${OBJ}
	rm server client
re: fclean all
