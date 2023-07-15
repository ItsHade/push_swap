SRCS = src/push_swap.c \
		src/push_swap_utils.c \
		src/check_args.c \
		src/list.c \
		src/put_list.c \
		src/swap.c \
		src/push.c \
		src/rotate.c \
		src/reverse_rotate.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean: 	clean
				$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re 