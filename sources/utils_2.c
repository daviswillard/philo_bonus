/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:42:00 by dwillard          #+#    #+#             */
/*   Updated: 2021/11/23 12:54:18 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	free_philo(t_philosopher **philo)
{
	if (*philo)
		free((*philo));
	*philo = NULL;
	philo = NULL;
	return (0);
}

void	kill_all(pid_t *pid_mass, void *data)
{
	int		index;
	t_data	*datas;

	index = 0;
	if (data)
	{
		datas = (t_data *)data;
		while (index < datas->philo_count)
		{
			kill(pid_mass[index], SIGTERM);
			index++;
		}
	}
	else
	{
		while (pid_mass[index])
		{
			kill(pid_mass[index], SIGTERM);
			index++;
		}
	}
}

void	eat_func(int philo_count)
{
	int	status;
	int	counter;

	counter = 0;
	while (counter < philo_count && waitpid(0, &status, 0) > 0)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status))
			counter++;
		else
			return ;
	}
}
