#include "stdio.h"
#include "pthread.h"
#include "philo.h"

void	*philosopher(void *);

int	main(int argc, char **argv)
{
	t_philo			*persons;
	pthread_t		*threads;
	pthread_mutex_t		*block_monitor;
	char			*curr;
	char			s[500];
	int			*block_start;
	int			*block_length;
	int			how_many_people;
	long			t0;
	long			ttmp;
	long			ttmp2;
	int			total;
	int			i;

	if (argc != 3)
		__exit__(NULL);
	how_many_people = atoi(argv[1]);
	srandom(time(0));
	
	/* malloc section */

	threads = (pthread_t *) malloc(sizeof(pthread_t) * how_many_people);
	if ( !threads )
		__exit__("malloc threas");
	persons = (t_philo *) malloc(sizeof(t_philo) * how_many_people);
	if ( !persons )
		__exit__("malloc persons");
	block_length = (int *) malloc(sizeof(int) * how_many_people);
	if ( !block_length )
		__exit__("malloc block_length");
	block_start = (int *) malloc(sizeof(int) * how_many_people);
	if ( !block_start )
		__exit__("malloc block_start");
	block_monitor = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	if ( !block_monitor )
		__exit__("malloc block_monitor");

	/* mutex posix threads setup */

	pthread_mutex_init(block_monitor, NULL);
	i = -1;
	while (++i < how_many_people)
	{
		block_length[i] = 0;
		block_start[i] = -1;
	}

	/* table ie. philosophers setup */

	t0 = time(0);
	i = -1;
	while (++i < how_many_people)
	{
		persons[i].id = i;
		persons[i].t0 = t0;
		persons[i].v = initialize_v( how_many_people ); // no action yet
		persons[i].ms = atoi(argv[2]);
		persons[i].block_length = block_length;
		persons[i].block_start = block_start;
		persons[i].block_monitor = block_monitor;
		persons[i].how_many_people = how_many_people;

		pthread_create( & threads[i], NULL, philosopher, (void *) (& persons[i]) );
		//pthread_create(threads + i, NULL, philosopher, (void *) (persons + i));
	}

	/* each one enters one's block */

	while(1)
	{
		/* mutex locked */

		pthread_mutex_lock( block_monitor );
		ttmp = time(0);
		curr = s;
		total = 0;
		while (++i < how_many_people)
		{
			total += block_length[i];
	      		if (block_start[i] != -1)
			{
				total += ttmp - block_start[i];
			}
		}
		sprintf(curr, "%3ld Total block_length: %5d : ", ttmp - t0, total);
		curr = s + strlen(s);
		while (++i < how_many_people)
		{
			ttmp2 = block_length[i];
			if (block_start[i] != -1)
			{
				ttmp2 += ttmp - block_start[i];
			}
      			sprintf(curr, "%5ld ", ttmp2);
			curr = s + strlen(s);
		}

		/* unlocked */

		pthread_mutex_unlock( block_monitor );
		printf("%s \n", s);
		fflush(stdout);
		sleep(10);
	}
}

void	*philosopher(void *v)
{
	t_philo	*persons;
	long	st;
	long	t;

	persons = (t_philo *) v;
	while(1)
	{

		/* First the philosopher thinks for a random number of seconds */

		st = (random()%persons->ms) + 1;
		printf("%3ld Philosopher %d thinking for %ld second%s\n", 
				time(0) - persons->t0, persons->id,
				st, (st <= 1) ? "" : "s");
		fflush(stdout);
		sleep(st / 100);

		/* Now, the philosopher wakes up and wants to eat
		 * He calls pick_up( ) to pick up the chopersonsticks 
		 */

		printf("%3ld Philosopher %d no longer thinking \
				-- calling pick_up()\n", 
				time(0) - persons->t0, persons->id);
		fflush(stdout);
		t = time(0);
		pthread_mutex_lock(persons->block_monitor);
		persons->block_start[persons->id] = t;
		pthread_mutex_unlock(persons->block_monitor);
		pick_up(persons);
		pthread_mutex_lock(persons->block_monitor);
		persons->block_length[persons->id] += (time(0) - t);
		persons->block_start[persons->id] = -1;
		pthread_mutex_unlock(persons->block_monitor);

		/* When pick_up returns, the philosopher can eat for a random number of seconds */

		st = (random()%persons->ms) + 1;
		printf("%3ld Philosopher %d eating for %ld second%s\n", 
				time(0) - persons->t0,
				persons->id, st,
				(st <= 1) ? "" : "s");
		fflush(stdout);
		sleep(st);

		/* Finally, the philosopher is done eating
		 * he calls put_down( ) to put down the chopersonsticks */

		printf("%3ld Philosopher %d no longer eating \
				-- calling put_down()\n",
				time(0) - persons->t0,
				persons->id);
		fflush(stdout);
		put_down(persons);
	}
}
