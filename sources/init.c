/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:59:18 by dwillard          #+#    #+#             */
/*   Updated: 2021/11/22 14:02:26 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_philosopher	*philo_init(int index, t_data *data)
{
	t_philosopher	*ret;

	if (!data)
		return (NULL);
	ret = malloc(sizeof(t_philosopher));
	if (!ret)
		return (NULL);
	ret->eaten = 0;
	ret->name = index + 1;
	ret->data = data;
	ret->last_eat = 0;
	return (ret);
}

t_data	*data_init(int argc, char **argv)
{
	t_data	*ret;

	ret = malloc(sizeof(t_data));
	if (!ret)
		return (NULL);
	ret->life_status = 1;
	ret->philo_count = ft_atoi(argv[1]);
	ret->time_to_die = ft_atoi(argv[2]);
	ret->time_to_eat = ft_atoi(argv[3]);
	ret->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		ret->eat_count = ft_atoi(argv[5]);
	else
		ret->eat_count = -1;
	sem_unlink("forks");
	ret->forks = sem_open("forks", O_CREAT, 0644, ret->philo_count);
	sem_unlink("writer");
	ret->writer = sem_open("write", O_CREAT, 0644, 1);
	ret->is_dead = 0;
	return (ret);
}
