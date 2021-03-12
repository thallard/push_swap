SRCS =	srcs/main.c \
		srcs/utils.c \
		srcs/comparaisons.c \
		srcs/parsing.c \
		srcs/operations/push_and_swap_stacks.c \
		srcs/operations/rotate_stacks.c \
		srcs/utils/printers_and_plages.c \
		srcs/utils/malloc_and_free.c \
		srcs/utils/lst_utils.c

OBJS = ${SRCS:.c=.o}

HEADER = includes/global.h includes/libft.h

NAME = push_swap

CC = gcc

RM = rm -f


FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

%.o: %.c	${HEADER}
			${CC} ${FLAGS} -c  $< -o ${<:.c=.o} 


$(NAME):	${OBJS}
			${CC} $(FLAGS) ${OBJS}  -L. -lft  -o ${NAME}  

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
