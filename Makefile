SRC_DIR	:= main/
OBJ_DIR	:= obj/


utils = utils
operations = operations


OBJ_DIRS = $(addprefix $(OBJ_DIR), $(main) $(utils) $(operations))

PRE_SRCS	=	main \
				mini_algo \
				$(utils)/utils \
				$(utils)/comparaisons \
				parsing \
				$(operations)/push_and_swap_stacks \
				$(operations)/rotate_stacks \
				$(operations)/reverse_rotate_both \
				$(utils)/printers_and_plages \
				$(utils)/malloc_and_free \
				$(utils)/reverse_tab \
				$(utils)/lst_utils

CHECK_SRCS = 	checker \
				mini_algo \
				$(utils)/utils \
				$(utils)/comparaisons \
				parsing \
				$(operations)/push_and_swap_stacks \
				$(operations)/rotate_stacks \
				$(operations)/reverse_rotate_both \
				$(utils)/printers_and_plages \
				$(utils)/malloc_and_free \
				$(utils)/reverse_tab \
				$(utils)/lst_utils

SRCS = $(addsuffix .c, $(addprefix $(SRC_DIR), $(PRE_SRCS)))
OBJS = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(PRE_SRCS)))
CHECKER_SRCS = $(addsuffix .c, $(addprefix $(SRC_DIR), $(CHECK_SRCS)))
CHECKER_OBJS = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(CHECK_SRCS)))

LIBFTA = libft/libft.a
NAME = push_swap
NAME_S = checker
CC = clang
RM = rm -f

# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -g3
INC = -I./includes -L./libft -lft

all:	libft $(NAME)

$(NAME): $(LIBFTA) $(OBJ_DIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME) 
	@echo "----- \033[32m $@ created\033[0m  -----"

coucou: libft $(NAME_S)

$(NAME_S): $(LIBFTA) $(OBJ_DIRS) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(INC) -o checker 
	@echo "----- \033[32m $@ created\033[0m  -----"

$(OBJ_DIRS):
	mkdir -p $(OBJ_DIRS)

$(OBJS) : includes/push_swap.h

$(CHECKER_OBJS) : includes/push_swap.h

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ \033[32mcreated\033[0m"

$(LIBFTA):
	@$(MAKE) -C ./libft

libft:
	@$(MAKE) -C ./libft

clean:
	rm -rf $(OBJ_DIR) $(NAME) $(CHECKER)
	@$(MAKE) clean -C libft

fclean: 	clean
			@$(RM) libft/libft.a
			rm -f push_swap checker

re:		fclean all

.PHONY: all clean fclean re libft checker
