/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:37:58 by terussar          #+#    #+#             */
/*   Updated: 2023/06/23 18:27:41 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

long	ft_time_us()
{
	struct timeval current_time;
	long	time_ms;
	
	gettimeofday(&current_time, NULL);
	time_ms = (current_time.tv_usec) + (current_time.tv_sec * 1000000);
	return (time_ms);
}

int	is_dead(t_philo	*philo)
{
	philo->time = ft_time_us() - philo->start_time;
	if ((philo->time - philo->last_time_eat) < philo->r_philo->time_to_die)
		return (0);
	else
	{
		philo->time = ft_time_us() - philo->start_time;
		printf("\033[0;31m%ld\t%d\tis dead\n\033[0m", philo->time, philo->id);
		return (1);
	}
}

int	ft_eat(t_philo *philo1)
{
	pthread_mutex_lock(&philo1->fork_id);
	pthread_mutex_lock(&philo1->fork_id_next);

	printf("%ld\t%d\thas take a fork\n", ft_time_us() - philo1->start_time, philo1->id);
	printf("%ld\t%d\thas take a fork\n", ft_time_us() - philo1->start_time, philo1->id);
	printf("%ld\t%d\tis eating\n", ft_time_us() - philo1->start_time, philo1->id);
	usleep(philo1->r_philo->time_to_eat);
	philo1->last_time_eat = ft_time_us(); // MARK : heure du dernier repas
	philo1->nb_meal--;

	pthread_mutex_unlock(&philo1->fork_id);
	pthread_mutex_unlock(&philo1->fork_id_next);
	return (0);
}

int	ft_sleep(t_philo *philo1)
{
	printf("%ld\t%d\tis sleeping\n", ft_time_us() - philo1->start_time, philo1->id);
	usleep(philo1->r_philo->time_to_sleep);
	return (0);
}

int	ft_think(t_philo *philo1)
{
	printf("%ld\t%d\tis thinking\n", ft_time_us() - philo1->start_time, philo1->id);
	return (0);
}