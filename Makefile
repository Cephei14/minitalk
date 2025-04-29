NAME	=	minitalk

CC	=	gcc

FLAGS	=	-Wall -Wextra -Werror

SRCS	=	client.c server.c

OBJ	=	$(SRCS:%.c=%.o)

all:	${NAME}

%.o:	%.c
		${CC} ${FLAGS} -c $< -o $@