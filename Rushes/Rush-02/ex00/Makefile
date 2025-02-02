SRCS_DIR = ./srcs/

SRC = main.c ft_check_args.c ft_check_dict.c ft_condition.c ft_free.c ft_init.c ft_manage_dict.c ft_print1.c ft_print2.c ft_aff.c ft_split.c ft_3_nbr.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC))

SRCS_OBJ = $(SRCS:.c=.o)

HEADER_DIR = ./includes/

DICT_DIR = ./dicts/

NUMBER ?= 42
DICT ?= $(DICT_DIR)numbers.dict

CC = cc

CFLAGS = -Wall -Wextra -Werror

OUTPUT = rush-02

all: print_animation $(OUTPUT)

print_animation:
	@echo "\033[1;33m"
	@echo "   _ _ _   ___   ___   _____ "
	@echo "  |  _  \ |_ _| /_ _\ |_   _|"
	@echo "  | |_| |  | |  | |_    | |"
	@echo "  |_ _ _/ |_ _| \_ _/   |_|    42porto"
	@echo "\033[1;36m\nBuilding $(OUTPUT)...\033[0m"
	@echo "\033[1;35m\n  made with love by adavid-a, edgribei, frnicola ❤️\033[0m"
	@echo ""

.c.o:
	${CC} ${CFLAGS} -I ${HEADER_DIR} -c $< -o ${<:.c=.o}

$(OUTPUT) : $(SRCS_OBJ)
	${CC} ${CFLAGS} -o ${OUTPUT} ${SRCS_OBJ}

leak: $(OUTPUT)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(OUTPUT) $(NUMBER) $(DICT)

clean:
	@rm -f $(SRCS_OBJ)
	@echo "\033[1;32mcleaned\033[0m"

fclean: clean
	@rm -f $(OUTPUT)
	@echo "\033[1;32mfully cleaned\033[0m"

re: fclean all

.PHONY: all print_animation clean fclean re leak
