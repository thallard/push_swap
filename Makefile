SRCS =	main/main.c \
		main/mini_algo.c \
		main/utils/utils.c \
		main/utils/comparaisons.c \
		main/parsing.c \
		main/operations/push_and_swap_stacks.c \
		main/operations/rotate_stacks.c \
		main/utils/printers_and_plages.c \
		main/utils/malloc_and_free.c \
		main/utils/reverse_tab.c \
		main/utils/lst_utils.c

SRCS_CHECKER =	main/checker.c \
				main/mini_algo.c \
				main/utils/utils.c \
				main/utils/comparaisons.c \
				main/parsing.c \
				main/operations/push_and_swap_stacks.c \
				main/operations/rotate_stacks.c \
				main/utils/printers_and_plages.c \
				main/utils/malloc_and_free.c \
				main/utils/lst_utils.c \
				main/utils/reverse_tab.c

OBJS = ${SRCS:.c=.o}

OBJS_CHECKER = ${SRCS_CHECKER:.c=.o}

HEADER = includes/push_swap.h includes/libft.h

NAME = push_swap

CHECKER = checker

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

%.o: %.c	${HEADER}
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}


$(NAME):	${OBJS}
			${CC} $(FLAGS) ${OBJS}  -L. -lft -o ${NAME}

$(CHECKER):	${OBJS_CHECKER}
			${CC} $(FLAGS) ${OBJS_CHECKER}  -L. -lft -o ${CHECKER}

all:		$(NAME)

clean:
			${RM} ${OBJS} ${OBJS_CHECKER}

fclean:		clean
			${RM} ${NAME} ${CHECKER}

re: fclean all

.PHONY: all clean fclean re checker
