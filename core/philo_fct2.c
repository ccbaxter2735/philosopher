/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:50:34 by terussar          #+#    #+#             */
/*   Updated: 2023/09/06 15:11:09 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	ft_usleep(t_philo *philo, long time)
{
	long	time2;

	if (is_dead(philo) != 0)
		exit(1);
	time2 = ft_time();
	while ((ft_time() - time2) < time)
	{
		if (is_dead(philo) != 0)
			exit(1);
		usleep(50);
	}
}