CFLAGS	= -Wall -Wextra -Werror
CC		= gcc
NAME		= bsq
RM		= rm -f
RUN		= ./${NAME}
RUNWF	= ${RUN} ${RFLAGS}

SRCDIR	= srcs
INCDIR	= includes

SRCS	= ${SRCDIR}/parsing_maze.c \
	  		${SRCDIR}/ft_utils.c \
			${SRCDIR}/ft_bmatrix.c \
			${SRCDIR}/ft_solve.c \
	  		main.c
OBJS	= ${SRCS:.c=.o}

all:		${NAME}

%.o:%.c
			${CC} ${CFLAGS} -c $< -o $@ -I ${INCDIR}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o $@ ${OBJS}

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all

.PHONY : 	re fclean clean all file
