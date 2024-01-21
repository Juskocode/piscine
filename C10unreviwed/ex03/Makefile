DIRSRC		= srcs/

SRCS		= ${DIRSRC}main.c ${DIRSRC}no_args.c ${DIRSRC}gest_args.c ${DIRSRC}ft_putchar.c ${DIRSRC}ft_putstr.c ${DIRSRC}ft_strcmp.c ${DIRSRC}ft_strlen.c ${DIRSRC}ft_swap.c ${DIRSRC}ft_file_read.c ${DIRSRC}ft_putnbr.c ${DIRSRC}ft_atoi.c

OBJS		= ${SRCS:.c=.o}

NAME		= ft_tail

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

${NAME}:	${OBJS}
			gcc -o ${NAME} ${OBJS} ${CFLAGS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
