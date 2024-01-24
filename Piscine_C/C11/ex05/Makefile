SRC = ft_aff.c ft_add.c ft_sub.c ft_mull.c ft_div.c ft_mod.c doop.c ft_atoi.c main.c

SRCS = $(addprefix $(PRE), $(SRC))

OBJS = $(SRCS:.c=.o)

PRE = ./srcs/

HEAD = ./includes/

NAME = do-op

RM = rm -f

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(GCC) $(CFLAGS) -I $(HEAD) -c $< -o $@

$(NAME): $(OBJS)
	$(GCC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

