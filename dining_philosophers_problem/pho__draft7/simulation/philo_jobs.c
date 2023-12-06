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
	philo->last_meal = ft_current_ms();
	if (philo->last_meal == -1)
		return (0);
	philo->eaten += 1;
	pthread_mutex_unlock(& philo->table->mtx_meals);
	if (everyone_ate_enough(philo))
	{
		philo_pass_time(philo,(long)philo->table->time_to_eat);
		philo_put_down(philo);
		// philo_print_task(philo, "everyone ate enough");
		return (0);
	}
	philo_pass_time(philo,(long)philo->table->time_to_eat);
	philo_put_down(philo);
	// if (! philo_put_down(philo))
	// 	return (0);
	return (1);
}

// int	philo_pick_up(t_philo *p)
// {
// 	int			left;
// 	int			right;

// 	right = p->id % p->table->total_philo;
// 	left = p->id - 1;
// 	if (left % 2)
// 	{
// 		pthread_mutex_lock(& p->chops[left]);
// 		philo_print_task(p, "picks up the left chopstick  \t\t  | Left");
// 		pthread_mutex_lock(& p->chops[right]);
// 		philo_print_task(p, "picks up the right chopstick  \t\t  |\t\tRight");
// 	}
// 	else
// 	{
// 		if (p->table->total_philo ^ 1)
// 		{
// 			pthread_mutex_lock(& p->chops[right]);
// 			philo_print_task(p, "picks up the right chopstick  \t\t  |\t\tRight");
// 		}
// 		pthread_mutex_lock(& p->chops[left]);
// 		philo_print_task(p, "picks up the left chopstick  \t\t  | Left");
// 	}
// 	philo_print_task(p, "is eating");
// 	return (1); // 
// }

int	philo_pick_up(t_philo *philo)
{
	int				right;
	int				left;

	right = philo->id % philo->table->total_philo;
	left = philo->id - 1;
	pthread_mutex_lock(& philo->chops[ ft_minmax(left, right, 0) ]);
	philo_print_chops(philo, left, right, ( ft_minmax(left, right, 0) ), UP);
	if (left == right)
	{
		pthread_mutex_unlock(& philo->chops[ft_minmax(left, right, 0)]);
		return (0);
	}
	pthread_mutex_lock(& philo->chops[ft_minmax(left, right, 1)]);
	philo_print_chops(philo, left, right, ( ft_minmax(left, right, 0) ), UP);
	philo_print_task(philo, "is eating"); // TO Try :: can try move this line to philo_eat
	return (1);
}

void	philo_print_chops(t_philo *p, int left, int right, int choice, int side)
{
	if (side == UP)
	{
		if (choice == left)
			philo_print_task(p, "has taken the chopstick one the left");
		else if (choice == right)
			philo_print_task(p, "has taken the chopstick one the right");
	}
	else if (side == DOWN)
	{
		if (choice == left)
			philo_print_task(p, "has put down the chopstick one the left");
		else if (choice == right)
			philo_print_task(p, "has put down the chopstick one the right");
	}
}

// int	philo_pick_up(t_philo *philo)
// {
// 	int				right;
// 	int				left;
	

// 	right = philo->id % philo->table->total_philo;
// 	left = philo->id - 1;
// 	pthread_mutex_lock(& philo->chops[ft_minmax(left, right, 0)]);
// 	philo_print_task(philo, "has taken a chopstick");
// 	if (left == right)
// 	{
// 		pthread_mutex_unlock(& philo->chops[ft_minmax(left, right, 0)]);
// 		return (0);
// 	}
// 	pthread_mutex_lock(& philo->chops[ft_minmax(left, right, 1)]);
// 	philo_print_task(philo, "has taken a chopstick");
// 	philo_print_task(philo, "is eating"); // TO Try :: can try move this line to philo_eat
// 	return (1);
// }

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

// int	philo_put_down(t_philo *p)
// {
// 	int		left;
// 	int		right;

// 	right = p->id % p->table->total_philo;
// 	left = p->id - 1;
// 	if (left % 2)
// 	{	
// 		pthread_mutex_unlock(& p->chops[right]);
// 		pthread_mutex_unlock(& p->chops[left]);
// 	}
// 	else
// 	{
// 		// added: only-one-philo check
// 		if (p->table->total_philo == 1) // new
// 		{
// 			pthread_mutex_unlock(& p->chops[left]);
// 			return 0;
// 		}
// 		pthread_mutex_unlock(& p->chops[left]);
// 		pthread_mutex_unlock(& p->chops[right]);
// 	}
// 	return (1);
// }

int	philo_put_down(t_philo *philo)
{
	int		left;
	int		right;

	right = philo->id % philo->table->total_philo;
	left = philo->id - 1;
	// if (right == left)
	// 	return (0);
	pthread_mutex_unlock(& philo->chops[ft_minmax(left, right, 1)]);
	philo_print_chops(philo, left, right, ( ft_minmax(left, right, 1) ), DOWN);
	pthread_mutex_unlock(& philo->chops[ft_minmax(left, right, 0)]);
	philo_print_chops(philo, left, right, ( ft_minmax(left, right, 0) ), DOWN);
	return (1);
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
	philo_pass_time(p, idle_time);

	/* added below part . idle time for thinking */
	// (old ver.:  thinking does not spend time)

	idle_time = p->table->time_to_eat - p->table->time_to_sleep; // new
	if (p->table->total_philo ^ 1)
		philo_print_task(p, "thinks");
	philo_pass_time (p, idle_time); // new
}

/*
void	philo_sleep(t_philo *p)
{
	long long		idle_time;

	if (p->table->total_philo ^ 1)
		philo_print_task(p, "sleeps");
	idle_time = p->table->time_to_sleep;
	philo_pass_time(p, idle_time);
}

void	philo_think(t_philo *p)
{
	if (p->table->total_philo ^ 1)
		philo_print_task(p, "thinks");
}
*/
