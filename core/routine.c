#include "../includes/philosopher.h"

void	*threading(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	// if ((philo->id % 2 == 0 && philo->r_philo->nb_philo % 2 == 0) || (philo->r_philo->nb_philo % 2 == 1
	// 		&& philo->id == philo->r_philo->nb_philo) || (philo->id % 2 == 0 && philo->r_philo->nb_philo % 2 == 1))
	// 		usleep(10);
	// while (philo->nb_meal != 0)
	// {
	// 	pthread_mutex_lock(&philo->r_philo->write);
	// 	take_time_and_str(philo, "action philo");
	// 	pthread_mutex_unlock(&philo->r_philo->write);
	// 	usleep(200000);
	// 	philo->nb_meal--;
	// 	// printf("%d\n", philo->nb_meal);
	// }
	if ((philo->id % 2 == 0 && philo->r_philo->nb_philo % 2 == 0) || (philo->r_philo->nb_philo % 2 == 1
		&& philo->id == philo->r_philo->nb_philo))
		ft_usleep(philo, philo->r_philo->time_to_eat - 10);
	while (is_dead(philo) == 0)
	{
		if (ft_eat(philo) != 0)
			break ;
		if (philo->nb_meal == 0)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (ft_think(philo) != 0)
			break ;
	}
	return (NULL);
}