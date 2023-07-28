/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:37:58 by terussar          #+#    #+#             */
/*   Updated: 2023/07/26 18:09:17 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	ft_eat(t_philo *philo1)
{
	if (is_dead(philo1) == 0)
	{
		printf(" id %d - fork gauche %d - fork droite %d\n", philo1->id, philo1->fork_id, philo1->fork_id_next);
		pthread_mutex_lock(&philo1->fork_id);
		pthread_mutex_lock(&philo1->r_philo->write);
		take_time_and_str(philo1, "has take a fork");
		pthread_mutex_unlock(&philo1->r_philo->write);

		pthread_mutex_lock(&philo1->fork_id_next);
		pthread_mutex_lock(&philo1->r_philo->write);
		take_time_and_str(philo1, "has take a fork");
		pthread_mutex_unlock(&philo1->r_philo->write);

		pthread_mutex_lock(&philo1->r_philo->write);
		take_time_and_str(philo1, "is eating");
		pthread_mutex_unlock(&philo1->r_philo->write);

		ft_usleep(philo1, philo1->r_philo->time_to_eat);
		pthread_mutex_unlock(&philo1->fork_id);
		pthread_mutex_unlock(&philo1->fork_id_next);
		philo1->last_time_eat = ft_time_us();
		if (philo1->nb_meal != -1)
			philo1->nb_meal--;
		return (0);
	}
	return (1);
}

int	ft_sleep(t_philo *philo1)
{
	if (is_dead(philo1) == 0)
	{
		pthread_mutex_lock(&philo1->r_philo->write);
		take_time_and_str(philo1, "is sleeping");
		pthread_mutex_unlock(&philo1->r_philo->write);
		ft_usleep(philo1, philo1->r_philo->time_to_sleep);
		return (0);
	}
	return (1);
}

int	ft_think(t_philo *philo1)
{
	if (is_dead(philo1) == 0)
	{
		pthread_mutex_lock(&philo1->r_philo->write);
		take_time_and_str(philo1, "is thinking");
		pthread_mutex_unlock(&philo1->r_philo->write);
		return (0);
	}
	return (1);
}
