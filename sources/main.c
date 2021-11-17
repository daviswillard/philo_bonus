/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:59:39 by dwillard          #+#    #+#             */
/*   Updated: 2021/11/08 20:00:13 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	parse_args(int argc, char **argv)
{
	int	philo_count;

	if (argc > 6 || argc < 5)
		return (-1);
	philo_count = ft_atoi(argv[1]);
	if (philo_count < 1 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0
		|| ft_atoi(argv[4]) < 0)
		return (-1);
	if (argc == 6 && ft_atoi(argv[5]) < 0)
		return (-1);
	return (0);
}

void	start(int argc, char **argv)
{
	t_data	*data;
	pid_t	*pid_mass;

	data = data_init(argc, argv);
	pid_mass = malloc(sizeof(pid_t *) * argc);
	if (!pid_mass || !data)
	{
		sem_unlink("forks");
		sem_unlink("write");
		free_that(&data, pid_mass);
		exit(0);
	}
	create_procs(pid_mass, data, argc);
}

int	main(int argc, char **argv)
{
	if (parse_args(argc, argv))
		return (write(2, "Param error\n", 12));
	start(argc, argv);
	return (0);
}
