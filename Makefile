SRCS =	srcs/main.c \
		srcs/utils.c

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
