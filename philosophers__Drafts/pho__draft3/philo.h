/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nxu              ...   ::::::::.fi       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "sys/time.h"
# include "pthread.h"
# include "stdio.h" /* printf */
# include "unistd.h" /* sleep . usleep */
# include "stdlib.h" /* free . malloc */
# include "./utils/print/print.h"

// every philo is a thread

typedef struct s_philo
{
	struct s_table	*table;
	pthread_t		thread;
	long long		last_meal;
	int				id;
	int				eaten;
}	t_philo;

// every chopstick has a mutex lock

typedef struct s_table
{
	pthread_mutex_t	*chops;
	pthread_mutex_t	mutex;
	long long		t0;
	int				total_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				flag_of_death;
	int				meals;
}	t_table;

/*	setup		*/

void		check_params(const int c, const char **v);
void		clean_exit(t_philo *p, t_table *t, int exit_granted);
void		parse_table(t_table *t, const int c, const char **v);
void		parse_philo(t_philo *p, int n);
void		usage_exit(void);

/*	printer debuggers	*/

void		print_endl(const char *_);
void		print_cout(const char *_);
void		print_params(const int c, const char **v);
void		print_table(t_table *table);
void		print_diners(t_philo *philos, int n);

/*	simulation	*/

void		simulation_jointhread(t_philo *philo, t_table *table);
void		simulation_initialize(t_philo *philo, t_table *table);
void		philo_pick_up(t_philo *p);
void		philo_put_down(t_philo *p);
void		philo_think(t_philo *p);
void		philo_sleep(t_philo *p);
void		philo_eat(t_philo *p);

/*	every thread has a routine of type void*	*/

void		*philo_routine(void *tmp);

/*	miscellaneous		*/

void		philo_spend_time(t_philo *p, long long n);
void		philo_print_task(t_philo *p, char *msg);
int			is_full(t_philo *p);
int			is_dead(t_philo *p);

/*	utils	*/

long long	ft_current_ms(void); // new
int			ft_atoll(const char *_);
int			ft_atoi(const char *_);
int			print(const char *_, ...);

#endif
