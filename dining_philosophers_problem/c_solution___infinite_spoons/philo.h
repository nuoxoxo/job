#include "stdlib.h"
#include "string.h"
#include "unistd.h" // time
#include "pthread.h"
#include "stdio.h"

typedef struct		s_philo
{
	int		how_many_people;
	int		id;		/* The philosopher's id: 0 to 5 */
	long		t0;		/* The time when the program started */
	long		ms;		/* The maximum time that philosopher eats/sleeps */
	int		*block_length;	/* Total time that a philosopher is blocked */
	int		*block_start;	/* If blocked, the time that he started blocking */
  	pthread_mutex_t *block_monitor;	/* monitor for block_time */             
	void		*v;		/* ? */
}			t_philo;

extern void	*initialize_v(int philo_count);
extern void	pick_up(t_philo *);
extern void	put_down(t_philo *);
extern void		__exit__(char *s);
