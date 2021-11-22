/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:00:01 by dwillard          #+#    #+#             */
/*   Updated: 2021/11/08 20:00:03 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	destroy_exit(t_philosopher *philo)
{
	t_data	*data;

	data = philo->data;
	free_philo(&philo);
	exit(0);
}
void	*watch(void *args)
{
	t_philosopher	*arg;
	u_int64_t		time;

	arg = (t_philosopher *)args;
	arg->last_eat = arg->data->start_time;
	while (1)
	{
		if (arg->data->eat_count >= 0 && arg->eaten >= arg->data->eat_count)
			destroy_exit(arg);
		if (get_time() > arg->last_eat + arg->data->time_to_die)
		{
			arg->data->is_dead = arg->name;
			time = get_time() - arg->data->start_time;
			sem_wait(arg->data->writer);
			printf("%6llu philosopher %d is dead\n", time, arg->data->is_dead);
			free_philo(&arg);
			exit(0);
		}
		ft_usleep(5);
	}
}
