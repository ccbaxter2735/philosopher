/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:55:17 by terussar          #+#    #+#             */
/*   Updated: 2023/06/27 20:18:42 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

long	ft_time_us()
{
	struct	timeval	current_time;
	long						time_ms;

	if(gettimeofday (&current_time, NULL) == -1)
	{
		ft_strerror("error\ngettimeofday returned -1\n");
		return (-1);
	}
	time_ms = (current_time.tv_usec / 1000) + (current_time.tv_sec * 1000);
	return (time_ms);
}

void	take_time_and_str(t_philo *philo, char *str)
{
	long	time;

	time = -1;
	time = ft_time_us() - philo->start_time;
	if (time > 0 && !check_death(philo, 0))
		printf("%ld %d %s\n", time, philo->id, str);
}

void	ft_usleep(t_philo *philo, long time)
{
	long	time2;

	if (is_dead(philo) != 0)
		exit(1);
	time2 = ft_time_us();
	while ((ft_time_us() - time2) < time)
	{
		if (is_dead(philo) != 0)
			exit(1);
		usleep(50);
	}
}

