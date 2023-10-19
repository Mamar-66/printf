SRC		=	printf.c ft_putstr.c ft_putchar.c

SRCS	= ${addprefix ${PRE}, ${SRC}}

SRCS_OBJS	= ${SRCS:.c=.o}

PRE		= ./src/

HEAD	= ./includes/

NAME	= libftprintf.a

RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${SRCS_OBJS}
			ar rc ${NAME} ${SRCS_OBJS}

clean:
		${RM} ${SRCS_OBJS} ${BONUS_OBJS}

fclean: clean	
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
