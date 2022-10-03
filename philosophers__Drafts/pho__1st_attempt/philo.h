#ifndef PHILO_H
# define PHILO_H

# include "sys/time.h"
# include "pthread.h"
# include "stdio.h" /* printf */
# include "unistd.h" /* sleep . usleep */
# include "stdlib.h" /* free . malloc */
# include "./print/print.h"


typedef struct s_philo
{
	struct s_table	*table;
	long long		t_0; // starting time
	long long		t_prev_meal; // starting of prior meal
	int				id;
	int				left_chop;
	int				right_chop;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				eaten;
}	t_philo;


typedef struct s_table
{
	pthread_mutex_t		writer_block; // msg printring is also a mutex
	pthread_mutex_t		*chops; // one mutex per chopstk
	pthread_t		*thread; // one thread per philo
	t_philo			*philo;
	long long		t_0;
	int				total_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				death; // death should be checked
	int				meals; // optonal
}	t_table;


/*		main			*/


void		dining_philosophers(t_table *_);
void		*waiter_routine(void *table);
void		*philo_routine(void *philo);


/*		philo's routine		*/


void		philo_eat(t_table *table, t_philo *philo);
void		philo_sleep(t_table *table, t_philo *philo);
void		philo_think(t_table *table, t_philo *philo);
void		philo_spend_time(long long time, t_table *table);
void		philo_write(t_table *table, t_philo *philo, char *msg);


/*		parsers			*/


void		setup_table(const int ___, const char **__, t_table *_);
void		check_params(const int c, const char **v);
void		setup_philo(t_table *_);
void		setup_time(t_table *table);
long long	fetch_time(t_table *table);
//long long	fetch_time(void);
//void		setup_mutex(t_table *_); /* deprecated */


/*		utils			*/


int			ft_atoll(const char *_);
int			ft_atoi(const char *_);
int			len(const char *); /* defined in print */


/*		printers		*/


void		__exit_safe__(t_table *_);
void		usage_exit(void);
void		print_endl(const char *_);
void		print_cout(const char *_);
void		print_params(const int c, const char **v);
void		print_diners(t_table *table);
void		print_table(t_table *table);
int			print(const char *_, ...);


#endif
