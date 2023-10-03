SRCS =	src/main.c \
		src/push_swap.c \
		src/utils.c \
		src/check_args.c \
		src/list.c \
		src/swap.c \
		src/push.c \
		src/rotate.c \
		src/reverse_rotate.c \
		src/split.c \
		src/ft_calloc.c \
		src/put.c \
		src/sort.c \
		src/sort_utils.c \
		src/get_cost.c \
		src/do_move.c

BONUS_SRCS =	src/list.c \
				src/put.c \
				bonus/rotate.c \
				bonus/reverse_rotate.c \
				bonus/push.c \
				bonus/swap.c \
				src/split.c \
				src/ft_calloc.c \
				bonus/checker.c \
				src/check_args.c \
				src/utils.c \
				bonus/get_next_line.c


OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = push_swap

BONUS_NAME = checker

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

bonus:		$(BONUS_OBJS)
			$(CC) $(FLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean: 	clean
			$(RM) $(NAME) $(BONUS_NAME)

re:			fclean all

.PHONY: all clean fclean re
