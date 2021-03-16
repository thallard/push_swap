SRCS =  ft_strlen.c ft_strdup.c \
        ft_atoi.c ft_isalnum.c \
        ft_isalpha.c ft_isascii.c \
        ft_isdigit.c ft_isprint.c \
        ft_split.c ft_toupper.c \
        ft_strdup.c ft_putnbr_fd.c \
        ft_strncmp.c ft_tolower.c \
        ft_strlcat.c ft_strlcpy.c \
        ft_strrchr.c ft_strchr.c \
        ft_strnstr.c ft_memset.c \
        ft_memcpy.c ft_bzero.c \
        ft_memccpy.c ft_memchr.c \
        ft_memmove.c ft_memcmp.c \
        ft_calloc.c ft_itoa.c \
        ft_strjoin.c ft_substr.c \
        ft_strtrim.c ft_strmapi.c \
        ft_putchar_fd.c ft_putstr_fd.c \
        ft_putendl_fd.c \
		get_next_line.c get_next_line_utils.c \
		ft_lstnew.c ft_lstadd_front.c \
        ft_lstsize.c ft_lstlast.c \
        ft_lstadd_back.c ft_lstdelone.c \
    	ft_lstclear.c ft_lstiter.c \
        ft_lstmap.c ft_printf.c \
		srcs/ft_checkers.c srcs/ft_utils.c srcs/ft_set_flags.c srcs/ft_utils.c srcs/ft_printers.c srcs/ft_setters.c \
		srcs/printers_each_type/ft_print_char.c srcs/printers_each_type/ft_print_hexadecimal.c srcs/printers_each_type/ft_print_int.c srcs/printers_each_type/ft_print_pointer.c srcs/printers_each_type/ft_print_unsigned_int.c

OBJS = ${SRCS:.c=.o}

HEADER = libft.h

NAME = libft.a

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

%.o: %.c	${HEADER}
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean bonus fclean re