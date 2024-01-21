DIRSRC		= ./srcs/

SRC		= main.c no_args.c gest_args.c prints.c ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c ft_file_read.c ft_putnbr.c ft_atoi.c ft_strdup.c

SRCS		= ${addprefix ${DIRSRC}, ${SRC}}

HEAD		= ./includes/

OBJS		= ${SRCS:.c=.o}

NAME		= ft_tail

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			gcc -o ${NAME} ${OBJS} ${CFLAGS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
