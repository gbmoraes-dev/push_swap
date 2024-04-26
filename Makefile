NAME = push_swap

PRINTF = libftprintf.a
LIBFT = libft.a

SRC_DIR = src
CMD_DIR = src/commands
ALGO_DIR = src/algorithms
UTILS_DIR = src/algorithms/utils

SRC_FILES = $(SRC_DIR)/errors.c $(SRC_DIR)/inputs.c $(SRC_DIR)/list.c
SRC_FILES += $(SRC_DIR)/node.c $(SRC_DIR)/main.c

CMD_FILES = $(CMD_DIR)/push.c $(CMD_DIR)/reverse_rotate.c $(CMD_DIR)/rotate.c $(CMD_DIR)/swap.c

ALGO_FILES = $(ALGO_DIR)/radix_sort.c $(ALGO_DIR)/sort_five.c $(ALGO_DIR)/sort_four.c $(ALGO_DIR)/sort_three.c

UTILS_FILES = $(UTILS_DIR)/utils.c

FILES = $(SRC_FILES) $(CMD_FILES) $(ALGO_FILES) $(UTILS_FILES)

OBJ:= $(FILES:.c=.o)

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

MSG1 = @echo "42@compile ✔️\nCompiled and now is working! 🚂💨"
MSG2 = @echo "42@cleaned ✔️\nWe cleaned the floor and now there's no .o files! 🧹"

all:	$(NAME)

$(NAME) : $(OBJ)
		@make -C libs/printf
		@make -C libs/libft
		@$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) libs/printf/$(PRINTF) libs/libft/$(LIBFT) -o $(NAME)
		$(MSG1)

clean : 
		@make clean -C libs/printf
		@make clean -C libs/libft
		@$(RM) $(OBJ)

fclean : clean
		@make fclean -C libs/printf
		@make fclean -C libs/libft
		@$(RM) $(NAME)
		@$(RM) $(PRINTF)
		@$(RM) $(LIBFT)
		$(MSG2)

re: fclean all

.PHONY:		all bonus clean fclean re