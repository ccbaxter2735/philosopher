/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:43:06 by terussar          #+#    #+#             */
/*   Updated: 2023/06/23 17:59:22 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO
# define PHILO

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_rules
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_x_eat; //option
}	t_rules;

typedef	struct	s_philo
{
	int	id;
	int	nb_meal;
	t_rules *r_philo;
	pthread_mutex_t fork_id;
	pthread_mutex_t fork_id_next;
	pthread_mutex_t	die_id;
	pthread_mutex_t	*mutex_id;
	long	start_time;
	long	last_time_eat;
	long	last_time_sleep;
	long	time;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	t_philo *philo;
	// pthread_mutex_t	*fork_id;
	pthread_t *th_id;
	t_rules rules;
	pthread_mutex_t	mutex_id;
	
} t_data;

int 	ft_strlen(char *str);
void	ft_strerror(char *str);
int		ft_atoi(char *str);
void	ft_bzero(void *str, size_t n);

void	*threading(void *arg);

int		ft_eat(t_philo *philo1);
int		ft_sleep(t_philo *philo1);
int		ft_think(t_philo *philo1);

int		is_dead(t_philo	*philo);
long	ft_time_us();

#endif
