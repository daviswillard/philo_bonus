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

static void	destroy_exit(t_data *data)
{
	sem_close(data->writer);
	sem_close(data->forks);
	exit(1);
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
			destroy_exit(arg->data);
		if (get_time() > arg->last_eat + arg->data->time_to_die)
		{
			arg->data->life_status = 0;
			arg->data->is_dead = arg->name;
			time = get_time() - arg->data->start_time;
			sem_wait(arg->data->writer);
			printf("%6llu philosopher %d is dead\n", time, arg->data->is_dead);
			destroy_exit(arg->data);
		}
		ft_usleep(5);
	}
}
