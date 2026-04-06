NAME			= philo
CC				= cc -g #o -g serve apenas para debug
CFLAGS			= -Wall -Werror -Wextra -Iincludes

VFLAG			+= --leak-check=full --show-leak-kinds=all --track-origins=yes # adicionar hellgrind
HFLAG			= --tool=helgrind

SRCS		+= $(addprefix srcs/, main.c utils.c error_routine.c argv_checker.c)

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

thread: fclean
	$(CC) $(CFLAGS) -g3 -fsanitize=thread $(SRCS) -o $(NAME)
	./$(NAME) 5 800 200 200

v:
	valgrind $(VFLAG) ./$(NAME)

h: $(NAME)
	valgrind $(HFLAG) ./$(NAME) 5 800 200 200

.PHONY: all clean fclean re v