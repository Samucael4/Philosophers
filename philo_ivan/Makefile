NAME    := philo
CC      := cc
CFLAGS	:= -Wall -Werror -Wextra
LDFLAGS	:= -lpthread

CFILES	:= better_usleep.c
CFILES	+= clean.c
CFILES	+= create_forks_philos.c
CFILES	+= ft_atol.c
CFILES	+= ft_isdigit.c
CFILES	+= ft_isspace.c
CFILES	+= ft_mod.c
CFILES	+= ft_strlen.c
CFILES	+= get_set.c
CFILES	+= get_time.c
CFILES	+= monitor.c
CFILES	+= parse_input.c
CFILES	+= philo.c
CFILES	+= settings.c
CFILES	+= start_sim_philos.c
CFILES	+= stats.c
CFILES	+= write_log.c
OBJS	:= $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CLIBS) -c $(CFILES)

run:
	./philo

clean:
	rm  -rf $(NAME)

fclean: clean
	rm -rf $(OBJS)

re: fclean all

.PHONY: re flcean clean run all