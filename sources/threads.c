/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:59:45 by dwillard          #+#    #+#             */
/*   Updated: 2021/11/08 19:59:52 by dwillard         ###   ########.fr       */
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
	sem_wait(philo->data->forks);
	sem_wait(philo->data->forks);
	philo->eaten++;
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
	while (1)
	{
		forks_action(philo);
		eat(philo);
		if ((philo->data->eat_count >= 0 && philo->eaten
				>= philo->data->eat_count))
			break ;
		print(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
		print(philo, "is thinking");
		if (!philo->data->life_status)
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

void	create_procs(pid_t *pid_mass, t_data *data, int argc)
{
	int	index;
	int	temp;

	index = 0;
	data->start_time = get_time();
	while (index < argc)
	{
		temp = fork();
		if (temp == 0)
			init_philo(data, index);
		pid_mass[index] = temp;
		index++;
	}
}
