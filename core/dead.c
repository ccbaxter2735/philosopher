/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:04:30 by terussar          #+#    #+#             */
/*   Updated: 2023/08/24 14:11:10 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	is_dead(t_philo	*philo)
{
	philo->time = ft_time() - philo->start_time;
	if (philo->r_philo->end_b == 1)
		return (1);
	if ((philo->time - philo->last_time_eat) < philo->r_philo->time_to_die)
		return (0);
	else
	{
		pthread_mutex_lock(&philo->r_philo->end);
		philo->r_philo->end_b = 1;
		pthread_mutex_unlock(&philo->r_philo->end);
		pthread_mutex_lock(&philo->r_philo->write);
		take_time_and_str(philo, "is dead");
		pthread_mutex_unlock(&philo->r_philo->write);
		return (1);
	}
}