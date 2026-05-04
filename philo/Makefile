NAME			= philo
CC				= cc -g #o -g serve apenas para debug
CFLAGS			= -Wall -Werror -Wextra -Iincludes

VFLAG			+= --leak-check=full --show-leak-kinds=all --track-origins=yes # adicionar hellgrind
HFLAG			= --tool=helgrind

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

thread: fclean
	$(CC) $(CFLAGS) -g3 -fsanitize=thread $(SRCS) -o $(NAME)
	./$(NAME) 5 800 200 200

v:
	valgrind $(VFLAG) ./$(NAME) 5 600 200 200

h: $(NAME) clean
	valgrind $(HFLAG) ./$(NAME) 1 500 200 100

.PHONY: all clean fclean re v

# ./$(NAME) 5 800 200 200 5
# ./$(NAME) 5 800 200 200

# ./$(NAME) 5 400 200 100 5
# ./$(NAME) 5 400 200 100

# ./$(NAME) 1 800 200 200
# ./$(NAME) 5 800 200 200
# ./$(NAME) 5 800 200 200 7
# ./$(NAME) 4 410 200 200 (pq funciona, e eh suposto funcionar)
# ./$(NAME) 4 310 200 100 (pq morre, e eh suposto morrer!)
# ./$(NAME) 2 250 100 100


# como checar death delay?
# com o checar se nao rouba garfo?

#./philo 100 200 60 60