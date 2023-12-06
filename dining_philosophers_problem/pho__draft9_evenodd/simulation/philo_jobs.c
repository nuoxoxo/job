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

int	philo_eat(t_philo *philo)
{
	if (! philo_pick_up(philo))
		return (0);
	pthread_mutex_lock(& philo->table->mtx_meals);
	if (philo->last_meal == -1)
		return (0);
	philo->last_meal = ft_current_ms();
	philo->eaten += 1;
	pthread_mutex_unlock(& philo->table->mtx_meals);
	if (everyone_ate_enough(philo))
	{
		philo_pass_time(philo, philo->table->time_to_eat);
		philo_put_down(philo);
		return (0);
	}
	philo_pass_time(philo, philo->table->time_to_eat);
	philo_put_down(philo);
	return (1);
}

/*
 *
 *	Strategy to prevent deadlock:
 *
 *
 *	(2) Odd & even philos do different things
 *
 *
 *	Even-digit philos get their chopsticks in their own order, 	
 *	while Odd-digit philos get their chopsticks in a Different order. 
 *
 *	and then there won't be "circular wait"
 *
 *
 */

int	philo_pick_up(t_philo *philo)
{
	int				right;
	int				left;

	right = philo->id % philo->table->total_philo;
	left = philo->id - 1;
	if (left % 2)
	{
		pthread_mutex_lock(& philo->chops[left]);
		philo_print_pick_up(philo, left, right, left);
		pthread_mutex_lock(& philo->chops[right]);
		philo_print_pick_up(philo, left, right, right);
	}
	else
	{
		pthread_mutex_lock(& philo->chops[right]);
		philo_print_pick_up(philo, left, right, right);
		if (left == right)
		{
			return (pthread_mutex_unlock(& philo->chops[right]), 0);
		}
		pthread_mutex_lock(& philo->chops[left]);
		philo_print_pick_up(philo, left, right, left);
	}
	philo_print_task(philo, "is eating");
	return (1);
}

/*
 *
 *	Strategy to prevent deadlock:
 *
 *
 *	(1) Hierarchy
 *
 *
 *	one way to solve this issue is to give a priority or hierarchy 
 *	to each chopstick. 
 *
 *	in this route, each philosopher must pick up 
 *	the lowest (or highest - it doesn’t matter so long as we’re consistent) 
 *	numbered chopstick first.
 *
 *
 */

// int	philo_pick_up(t_philo *philo)
// {
// 	int				choice;
// 	int				right;
// 	int				left;

// 	right = philo->id % philo->table->total_philo;
// 	left = philo->id - 1;
// 	choice = ft_minmax(left, right, 0);
// 	pthread_mutex_lock(& philo->chops[choice]);
// 	philo_print_pick_up(philo, left, right, choice);
// 	if (left == right)
// 	{
// 		pthread_mutex_unlock(& philo->chops[choice]);
// 		return (0);
// 	}
// 	choice = ft_minmax(left, right, 1);
// 	pthread_mutex_lock(& philo->chops[choice]);
// 	philo_print_pick_up(philo, left, right, choice);
// 	philo_print_task(philo, "is eating");
// 	return (1);
// }

int	philo_put_down(t_philo *philo)
{
	int		right;
	int		left;

	right = philo->id % philo->table->total_philo;
	left = philo->id - 1;
	if (left % 2)
	{
		if (left == right)
		{
			return (0);
		}
		pthread_mutex_unlock(& philo->chops[right]);
		philo_print_put_down(philo, left, right, right);
		pthread_mutex_unlock(& philo->chops[left]);
		philo_print_put_down(philo, left, right, left);
	}
	else
	{
		pthread_mutex_unlock(& philo->chops[left]);
		philo_print_put_down(philo, left, right, left);
		pthread_mutex_unlock(& philo->chops[right]);
		philo_print_put_down(philo, left, right, right);
	}
	return (1);
}

// int	philo_put_down(t_philo *philo)
// {
// 	int		choice;
// 	int		right;
// 	int		left;

// 	right = philo->id % philo->table->total_philo;
// 	left = philo->id - 1;
// 	choice = ft_minmax(left, right, 1);
// 	pthread_mutex_unlock(& philo->chops[choice]);
// 	philo_print_put_down(philo, left, right, choice);
// 	choice = ft_minmax(left, right, 0);
// 	pthread_mutex_unlock(& philo->chops[choice]);
// 	philo_print_put_down(philo, left, right, choice);
// 	return (1);
// }

void	philo_pass_time(t_philo *philo, long long n)
{
	long long	start;
	long long	span;

	start = ft_current_ms();
	while (!someone_is_dead(philo) && !everyone_ate_enough(philo))
	{
		span = ft_current_ms() - start;
		if (span >= n)
			break ;
		usleep(100);
	}
}

int	ft_minmax(int x, int y, int op)
{
	if (op)
	{
		if (x > y)
			return (x);
		return (y);
	}
	if (x > y)
	{
		return (y);
	}
	return (x);
}
