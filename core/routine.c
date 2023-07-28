/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:28:25 by terussar          #+#    #+#             */
/*   Updated: 2023/07/26 18:12:58 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	*threading(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
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
