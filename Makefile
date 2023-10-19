SRCS		=	printf.c src/*.c

SRCS_OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	${SRCS_OBJS}
			ar rc ${NAME} ${SRCS_OBJS}
%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $<

all:	${NAME}

clean:
		${RM} ${SRCS_OBJS} ${BONUS_OBJS}

fclean: clean	
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
