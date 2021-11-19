/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:01:34 by dwillard          #+#    #+#             */
/*   Updated: 2021/11/08 20:01:36 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <semaphore.h>

typedef struct s_data
{
	int				philo_count;
	int				eat_count;
	int				life_status;
	int				is_dead;
	uint64_t		time_to_sleep;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		start_time;
	sem_t			*writer;
	sem_t			*forks;
}t_data;

typedef struct s_philosopher
{
	int				name;
	int				eaten;
	uint64_t		last_eat;
	t_data			*data;
}t_philosopher;

int				ft_atoi(const char *str);

uint64_t		get_time(void);

int				free_that(void *this, void *that);

int				free_philo(t_philosopher **philo);

void			print(t_philosopher *philo, char *message);

void			ft_usleep(uint64_t delta_t);

t_philosopher	*philo_init(int index, t_data *data);

void			*watch(void *args);

void			create_procs(pid_t *pid_mass, t_data *data);

t_data			*data_init(int argc, char **argv);

#endif
