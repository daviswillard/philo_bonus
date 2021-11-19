/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:59:57 by dwillard          #+#    #+#             */
/*   Updated: 2021/11/08 19:59:58 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_atoi(const char *str)
{
	int	ind;
	int	sgn;
	int	value;

	sgn = 1;
	ind = 0;
	value = 0;
	while (str[ind] == ' ' || (str[ind] >= '\t' && str[ind] <= '\r'))
		ind++;
	if (str[ind] == '-' || str[ind] == '+')
		if (str[ind++] == '-')
			sgn = -1;
	while (str[ind] >= '0' && str[ind] <= '9')
	{
		value *= 10;
		value += (str[ind++] - '0');
	}
	if (sgn == -1)
		value = -value;
	return (value);
}

uint64_t	get_time(void)
{
	struct timeval	s_tv;

	gettimeofday(&s_tv, NULL);
	return (s_tv.tv_sec * 1000 + s_tv.tv_usec / 1000);
}

void	ft_usleep(uint64_t delta_t)
{
	uint64_t	result;

	result = get_time() + delta_t;
	while (get_time() < result)
		usleep(100);
}

void	print(t_philosopher *philo, char *message)
{
	int			name;
	sem_t		*writer;
	uint64_t	time;

	time = get_time() - philo->data->start_time;
	writer = philo->data->writer;
	name = philo->name;
	if (!philo->data->life_status)
		return ;
	sem_wait(writer);
	printf("%6llu philosopher %d %s\n", time, name, message);
	sem_post(writer);
}

int	free_that(void *this, void *that)
{
	if (!this)
		;
	else
		free(this);
	if (!that)
		;
	else
		free(that);
	return (0);
}
