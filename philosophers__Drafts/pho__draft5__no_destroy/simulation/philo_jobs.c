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

#include "philo.h"

void	philo_eat(t_philo *p)
{
	int		idle_time;

	philo_pick_up(p);
	if (p->table->total_philo ^ 1)
	{
		philo_print_task(p, "starts eating");
	}
	p->last_meal = ft_current_ms();
	if (p->table->total_philo == 1)
	{
		idle_time = p->table->time_to_die;
		philo_spend_time(p, idle_time);
	}
	else
	{
		idle_time = p->table->time_to_eat;
		philo_spend_time(p, idle_time);
		p->eaten += 1;
	}
	philo_put_down(p);
}

void	philo_pick_up(t_philo *p)
{
	int		left;
	int		right;

	right = p->id % p->table->total_philo;
	left = p->id - 1;
	if (left % 2)
	{
		pthread_mutex_lock(& p->table->chops[left]);
		philo_print_task(p, "picks up the left chopstick  \t\t  | Left");
		pthread_mutex_lock(& p->table->chops[right]);
		philo_print_task(p, "picks up the right chopstick  \t\t  |\t\tRight");
	}
	else
	{
		if (p->table->total_philo ^ 1)
		{
			pthread_mutex_lock(& p->table->chops[right]);
			philo_print_task(p, "picks up the right chopstick  \t\t  |\t\tRight");
		}
		pthread_mutex_lock(& p->table->chops[left]);
		philo_print_task(p, "picks up the left chopstick  \t\t  | Left");
	}
}

/*
 *
 *	deadlock solution :
 *
 *		odd pho-eaters . start w/ the LEFT chopstick
 *		even pho-eaters . start with the RIGHT one
 *
 * 	*problem w/ this solution :
 *
 * 		if K == odd :
 * 			last pho-eater does not compete with anyone, 
 * 			while others have to wait for longer time
 *
 * 				0 vs 1
 * 				2 vs 3
 * 				4 vs 5
 * 				6 vs no one
 *
 * 		if K == even :
 * 			each philo in every pair is in fair competition
 *
 * 				0 vs 1
 * 				2 vs 3
 * 				4 vs 5
 * 				6 vs 7
 *
 *
 */

void	philo_put_down(t_philo *p)
{
	int		left;
	int		right;

	right = p->id % p->table->total_philo;
	left = p->id - 1;
	if (left % 2)
	{
		pthread_mutex_unlock(& p->table->chops[right]);
		pthread_mutex_unlock(& p->table->chops[left]);
	}
	else
	{
		// added: only-one-philo check
		if (p->table->total_philo == 1) // new
		{
			pthread_mutex_unlock(& p->table->chops[left]);
			return ;
		}
		pthread_mutex_unlock(& p->table->chops[left]);
		pthread_mutex_unlock(& p->table->chops[right]);
	}
}

/*
 *
 *	deadlock solution . part 2 :
 *
 *		in put_down() :
 *		
 *		the reverse order of chopsticks will be put down, ie. unlocked
 *
 * 			if K == odd :
 * 				unlock R
 * 				unlock L
 *
 * 			if K == even :
 * 				unlock L
 * 				unlock R
 *
 *
 */

void	philo_sleep_and_think(t_philo *p)
{
	long long		idle_time;

	if (p->table->total_philo ^ 1)
		philo_print_task(p, "sleeps");
	idle_time = p->table->time_to_sleep;
	philo_spend_time(p, idle_time);
	if (p->table->total_philo ^ 1)
		philo_print_task(p, "thinks");

	/* added below part . idle time for thinking */
	// (old ver.: thinking does not spend time)

	idle_time = p->table->time_to_eat - p->table->time_to_sleep; // new
	if (p->table->total_philo ^ 1)
		philo_print_task(p, "thinks");
	philo_spend_time (p, idle_time); // new
}

/*
void	philo_sleep(t_philo *p)
{
	long long		idle_time;

	if (p->table->total_philo ^ 1)
		philo_print_task(p, "sleeps");
	idle_time = p->table->time_to_sleep;
	philo_spend_time(p, idle_time);
}

void	philo_think(t_philo *p)
{
	if (p->table->total_philo ^ 1)
		philo_print_task(p, "thinks");
}
*/