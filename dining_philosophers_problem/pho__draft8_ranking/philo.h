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
# include "unistd.h" /* sleep . usleep */
# include "stdlib.h" /* free . malloc */
# include "stdio.h" /* printf */
# include "./utils/print/print.h"

# define UP 0
# define DOWN 1

/*	t		*/

typedef struct s_table
{
	pthread_mutex_t		mtx_death;
	pthread_mutex_t		mtx_print;
	pthread_mutex_t		mtx_meals;
	pthread_mutex_t		mtx_close;
	long long			t0;
	int					total_philo;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_die;
	int					flag_of_death;
	int					flag_of_close;
	int					meals;
}				t_table;

/*	p		*/

typedef struct s_philo
{
	pthread_mutex_t		*chops;
	t_table				*table;
	long long			last_meal;
	int					id;
	int					eaten;
}				t_philo;

/*	setup		*/

void		check_params(const int c, const char **v);
void		clean_exit(t_philo *p, t_table *t, int exit_granted);
void		void_cleaner(void *void_star);
int			parse_table(t_table *t, const int c, const char **v);
int			parse_philo(t_philo *p, t_table *t);
void		usage_exit(void);
void		ft_mutex_destroy(t_philo *p, t_table *t); // New in v7
void		simulation_monitor(t_philo *p, t_table *t);

/*	simulation	*/

void		simulation_init_all_mutex(t_philo *p, t_table *t);
void		simulation_launch_routine(t_philo *p, t_table *t, pthread_t *_);
void		simulation_join_pthreads(t_philo *p, t_table *t, pthread_t *_);
void		*philo_routine(void *tmp);

/*	strategy	*/

int			philo_eat(t_philo *p);
int			philo_pick_up(t_philo *p);
int			philo_put_down(t_philo *p);

/*	miscellaneous		*/

void		philo_pass_time(t_philo *p, long long n);
void		philo_print_task(t_philo *p, char *message);
void		philo_print_put_down(t_philo *p, int l, int r, int choice);
void		philo_print_pick_up(t_philo *p, int l, int r, int choice);
// void		philo_print_chops(t_philo *p, int l, int r, int choice, int side);

int			everyone_ate_enough(t_philo *p);
int			someone_is_dead(t_philo *p);
int			check_if_all_ate_enough(t_philo *p, t_table *t);
void		set_flag_of_death(t_table *t);
void		set_flag_of_close(t_table *t);
void		simulation_monitor(t_philo *p, t_table *t);
int			ft_minmax(int x, int y, int choice);

/*	toolkit	*/

long long	ft_current_ms(void);
int			ft_atoll(const char *_);
int			ft_atoi(const char *_);
int			print(const char *_, ...);

/*	printer debuggers	*/

void		print_endl(const char *_);
void		print_cout(const char *_);
void		print_params(const int c, const char **v);
void		print_table(t_table *t);
void		print_diners(t_philo *philos, int n);

#endif
