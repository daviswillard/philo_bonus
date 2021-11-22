/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:05:17 by dwillard          #+#    #+#             */
/*   Updated: 2021/11/22 14:47:25 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	eat(t_philosopher *philo)
{
	if (philo->last_eat + philo->data->time_to_die > get_time())
		philo->data->is_dead = philo->name;
	philo->last_eat = get_time();
	print(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	philo->eaten++;
//	if (philo->eaten > philo->data)
}

static void	forks_action(t_philosopher *philo)
{
	sem_wait(philo->data->forks);
	print(philo, "has taken a fork");
	if (philo->data->philo_count == 1)
	{
		ft_usleep(philo->data->time_to_die + 20);
		return ;
	}
	sem_wait(philo->data->forks);
	print(philo, "has taken a fork");
}

static void	*philosophy(t_philosopher *philo)
{
	t_data	*data;

	data = philo->data;
	while (1)
	{
		forks_action(philo);
		eat(philo);
		print(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
		print(philo, "is thinking");
		if (!data->life_status)
			break ;
	}
	free_philo(&philo);
	exit(0);
}

static void	init_philo(t_data *data, int name)
{
	t_philosopher	*philo;
	pthread_t		watcher;

	philo = philo_init(name, data);
	if ((philo->name % 2))
		ft_usleep(philo->data->time_to_eat);
	pthread_create(&watcher, NULL, watch, philo);
	pthread_detach(watcher);
	philosophy(philo);
}

void	create_procs(pid_t *pid_mass, t_data *data)
{
	int	index;
	int	temp;

	index = 0;
	data->start_time = get_time();
	while (index < data->philo_count)
	{
		temp = fork();
		if (temp == 0)
			init_philo(data, index);
		else if (temp < 0)
			break ;
		pid_mass[index] = temp;
		index++;
	}
	if (temp < 0)
		kill_all(pid_mass, NULL);
	waitpid(0, 0, 0);
	kill_all(pid_mass, data);
}
