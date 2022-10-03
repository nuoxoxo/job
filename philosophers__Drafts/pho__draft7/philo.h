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

typedef struct	s_table
{
	pthread_mutex_t		mtx_death; // set Death flag
	pthread_mutex_t		mtx_print;
	pthread_mutex_t		mtx_meals; // count meals
	pthread_mutex_t		mtx_close; // set Close flag
	long long			t0;
	int					total_philo;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_die;
	int					flag_of_death;
	int					flag_of_close; // max meals reached
	int					meals;
}				t_table;

typedef struct	s_philo
{
	// pthread_t			thread;
	pthread_mutex_t		*chops; // New
	long long			last_meal;
	int					id;
	int					eaten;
	t_table				*table; // Ud.
	// struct s_table		*table;
}				t_philo;

/*	setup		*/

void		check_params(const int c, const char **v);
void		clean_exit(t_philo *p, t_table *t, int exit_granted);
void		void_cleaner(void *void_star);
// void		parse_table(t_table *t, const int c, const char **v);
// void		parse_philo(t_philo *p, int n);
int			parse_table(t_table *t, const int c, const char **v);
// int			parse_philo(t_philo *p, int n);
int			parse_philo(t_philo *p, t_table *t);
void		usage_exit(void);

/*	printer debuggers	*/

void		print_endl(const char *_);
void		print_cout(const char *_);
void		print_params(const int c, const char **v);
void		print_table(t_table *table);
void		print_diners(t_philo *philos, int n);

void		ft_mutex_destroy(t_philo *philo, t_table *table); // New in v7
void		ft_arbitrator(t_philo *philo, t_table *table);

/*	simulation	*/

// void		simulation_jointhread(t_philo *philo, t_table *table);
void		simulation_join_pthreads(t_philo *p, t_table *t, pthread_t *_);
void		simulation_init_all_mutex(t_philo *p, t_table *t);
void		simulation_launch_routine(t_philo *p, t_table *t, pthread_t *_); // New in v7

// void		philo_pick_up(t_philo *p);
// void		philo_put_down(t_philo *p);
int			philo_pick_up(t_philo *p);
int			philo_put_down(t_philo *p);

// void		philo_eat(t_philo *p);
int			philo_eat(t_philo *p); // New in v7

void		philo_sleep_and_think(t_philo *p);

// void		philo_think(t_philo *p); // combined
// void		philo_sleep(t_philo *p); // combined

/*	every thread has a routine of type void*	*/

void		*philo_routine(void *tmp);

/*	miscellaneous		*/

void		philo_pass_time(t_philo *p, long long n);
void		philo_print_task(t_philo *p, char *msg);
void		philo_print_chops(t_philo *p, int l, int r, int choice, int side);

// int			end_is_nigh(t_philo *p); // new . added in v5
// int			end_is_nigh_again(t_philo *p, int flag_of_death); // TODO
// int			end_is_nigh_again(t_philo *p);
// int			is_full(t_philo *p);
// int			is_dead(t_philo *p);

int			everyone_ate_enough(t_philo *philo);
int			someone_is_dead(t_philo *philo);
int	check_if_all_ate_enough(t_philo *philo, t_table *table);

void	set_flag_of_death(t_table *table);
void	set_flag_of_close(t_table *table);

void 		ft_arbitrator(t_philo *philo, t_table *table);
int		ft_minmax(int x, int y, int op);
/*	utils	*/

long long	ft_current_ms(void); // new
int			ft_atoll(const char *_);
int			ft_atoi(const char *_);
int			print(const char *_, ...);

#endif
