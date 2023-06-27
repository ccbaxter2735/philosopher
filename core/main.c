/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:46:57 by terussar          #+#    #+#             */
/*   Updated: 2023/06/27 20:40:59 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"
// parsing int et lettre
void	initialize_arg(t_data *data, char **av, int ac)
{
	data->rules.nb_philo = ft_atoi(av[1]);
	data->rules.time_to_die = ft_atoi(av[2]);
	data->rules.time_to_eat = ft_atoi(av[3]);
	data->rules.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->rules.nb_x_eat = ft_atoi(av[5]);
	else
		data->rules.nb_x_eat = -1;
}

int	ft_malloc_thread(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->rules.nb_philo);
	if (!data->philo)
		return (1);
	data->th_id = malloc(sizeof(pthread_t) * data->rules.nb_philo);
	if (!data->th_id)
		return (1);
	ft_bzero(data->th_id, (sizeof(pthread_t) * data->rules.nb_philo));
	ft_bzero(data->philo, (sizeof(t_philo) * data->rules.nb_philo));
	return (0);
}

void	*initialize_thread(t_data *data)
{
	int		i;
	long	tmp;

	i = 0;
	if (ft_malloc_thread(data) == 1)
		return (NULL);
	pthread_mutex_init(&data->mutex_id, NULL);
	pthread_mutex_init(&data->rules.write, NULL);
	tmp = ft_time_us();
	while (i < data->rules.nb_philo)
	{
		data->philo[i].start_time = tmp;
		data->philo[i].nb_meal = data->rules.nb_x_eat;
		pthread_mutex_init(&data->philo[i].fork_id, NULL);
		i++;
	}
	i = 0;
	while (i < data->rules.nb_philo)
	{
		if ((i + 1) != data->rules.nb_philo)
			data->philo[i].fork_id_next = data->philo[i + 1].fork_id;
		else
			data->philo[i].fork_id_next = data->philo[0].fork_id;
		pthread_mutex_init(&data->philo[i].fork_id_next, NULL);
		i++;
	}
	i = 0;
	while (i < data->rules.nb_philo)
	{
		data->philo[i].mutex_id = &data->mutex_id;
		data->philo[i].id = i + 1;
		data->philo[i].r_philo = &data->rules;
		if (pthread_create(&data->th_id[i], NULL,
				&threading, &data->philo[i]) != 0)
			ft_strerror("error\nfailed to create thread\n");
		i++;
	}
	i = 0;
	while (i < data->rules.nb_philo)
	{
		if (pthread_join(data->th_id[i], NULL) != 0)
			ft_strerror("error\nfailed to join thread\n");
		pthread_mutex_destroy(&data->philo[i].fork_id);
		pthread_mutex_destroy(&data->philo[i].fork_id_next);
		i++;
	}
	pthread_mutex_destroy(&data->rules.write);
	pthread_mutex_destroy(&data->mutex_id);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		ft_strerror("error\nwrong number of arguments (5 or 6 required)\n");
	else
	{
		ft_bzero(&data, sizeof(data));
		initialize_arg(&data, av, ac);
		initialize_thread(&data);
	}
	return (0);
}
