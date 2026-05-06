NAME			= philo
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -Iincludes -pthread

SRCS		+= $(addprefix srcs/, main.c helpers_main.c utils.c helpers_routine.c routine_utils.c error_and_clean.c arg_check_get.c philo_movements.c preparation.c)

OBJS			= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re