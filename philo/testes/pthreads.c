#include "../includes/philophers.h"

typedef struct s_lyceum2
{
	int				i;
	pthread_mutex_t	mutex;
	int				resul;
}					t_lyceum2;

// merda de formatador fica colocando merda na assinatura da minha funcao
void	*simple_routine(void *l_arg)
{
	t_lyceum2	*l;

	l = (t_lyceum2 *)l_arg;
	pthread_mutex_lock(&l->mutex); // Passa o endereço do mutex da struct
	printf("thread leu: %i\n", l->i);
	if (l->i == 10)
		l->resul = 69;
	pthread_mutex_unlock(&l->mutex);
	// sleep(3);
	// printf("o que sera o fim disso\n");
	// para o projeto,
	// eh aqui que vai set os atos de
	// comer, dormir e pensar?
	// ta gerando race condition
	// ai que entra a porra da mutex
	return (void *)&l->resul;
}

int	main(int argc, char const *argv[])
{
	pthread_t	*man_of_plato;
	pthread_t	teste;
	int			x;
	t_lyceum2	l;
	int			*retorno;

	man_of_plato = malloc(sizeof(pthread_t) * 200);
	if (!man_of_plato)
		exit(EXIT_FAILURE);
	l.i = 0;
	pthread_mutex_init(&l.mutex, NULL); // o que seria o segundo atributo?
	while (l.i < 200)
	{
		// acho que onde to passando i, sera a struc do philosopher
		if (pthread_create(&man_of_plato[l.i], NULL, simple_routine, &l) != 0)
			printf("-=-%li-=-\n", teste);
		printf("thread %i start\n", l.i);
		l.i++;
	}
	l.i = 0;
	while (l.i < 200)
	{
		pthread_join(man_of_plato[l.i], (void *) &retorno);
		printf("thread %i end\n", l.i);
		printf("%d", *(int *)retorno);
		l.i++;
	}
	free(man_of_plato);
	pthread_mutex_destroy(&l.mutex);
	return (EXIT_SUCCESS);
}

// para criar uma thread, primeiro
// tem que definir um lugar onde
// a thread vai armazenar uma (API) numa var
// uma var do tipo pthread_t
// pthread_create(&t1, NULL, &simple_routine, NULL);
// o primeiro param, eh um ptr para t1 criado acima
// o segundo sao atributos de customizacao relacionados a threads,
// pode deixar NULL por hora
// o tericeiro eh a funcao que sera executada quando se criar a thread em si,
//	no caso a funcao criada
// anteriormente chamada simple_routine(o ptr dela)
// o ultimo sao os argumentos passados para a funcao,
//		como a minha nao tem nada,
//	nao passo nada
// apos isso,
//		temos que esperar a thread terminar a execucao de sua rotina
// usa-se pthread_join(),
//			eh tipo um wait ou waitpid mas para threads.
// passa-se a struct t1 com as infos e um ptr que pega os resultados pode ser NULL aqui
// ja que nao retornamos nem fazemos nada de especial com a thread

// o motivo para dois loops eh:
/*
Para colocar todos os filósofos na mesa "ao mesmo tempo",
devo usar o pthread_join dentro deste primeiro loop,
o segundo filósofo só começará a comer depois que o primeiro terminar
caso eu nao colocasse em loops separados.
cria tudo primeiro, e so depois faz o resto.
*/