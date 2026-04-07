#include "../includes/philophers.h"

// merda de formatador fica colocando merda na assinatura da minha funcao
void	*simple_routine(void *i)
{
	printf("testando threads %p\n", i);
	sleep(3);
	printf("o que sera o fim disso\n");
	// para o projeto, eh aqui que vai set os atos de
	// comer, dormir e pensar?

}

int	main(int argc, char const *argv[])
{
	pthread_t	*man_of_plato;
	int			i;
	int			verificacao_time_day;
	struct timeval	hora;
	long			total_tmp;

	// isso aqui da valor em microsegundos, preciso trabalhar com milisegundos
	verificacao_time_day = gettimeofday(&hora, NULL);
	if (verificacao_time_day == 0)
	{
		total_tmp = hora.tv_usec * 1000;
		total_tmp += hora.tv_usec / 1000;
		printf("real_time: %li || micro: %li || epoch: %li\n", total_tmp, hora.tv_usec, hora.tv_sec);
	}
	man_of_plato = malloc(sizeof(pthread_t) * 20);
	if (!man_of_plato)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < 20)
	{
		// acho que onde to passando i, sera a struc do philosopher
		pthread_create(&man_of_plato[i], NULL, simple_routine, &i);
		i++;
	}
	i = 0;
	while (i < 20)
	{
		pthread_join(man_of_plato[i], NULL);
		i++;
	}
	free(man_of_plato);
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