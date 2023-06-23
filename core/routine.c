/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:28:25 by terussar          #+#    #+#             */
/*   Updated: 2023/06/23 18:20:29 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	*threading(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *)arg;
	philo->time = ft_time_us() - philo->start_time;
	if (philo->id % 2 == 0)
	{
		ft_eat(philo);
		while (is_dead(philo) == 0 && philo->nb_meal != 0)
		{
			ft_sleep(philo);
			ft_think(philo);
			ft_eat(philo);
		}
	}
	else
	{
		while (is_dead(philo) == 0 && philo->nb_meal != 0)
		{
			ft_sleep(philo);
			ft_think(philo);
			ft_eat(philo);
		}
	}
	return NULL;
}
