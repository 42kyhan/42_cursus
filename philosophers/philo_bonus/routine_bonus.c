/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:30:20 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/20 21:30:39 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	routine(t_game *game)
{
	game->time = get_time();
	while (1)
	{
		philo_eat(game);
		philo_sleep(game);
	}
}

int	start_philo(t_game *game)
{
	int	i;

	i = 0;
	game->time = get_time();
	while (i < game->philo_num)
	{
		game->philo.id = i;
		game->pid_philo[i] = fork();
		if (game->pid_philo[i] == -1)
		{
			while (--i >= 0)
				kill(game->pid_philo[i], SIGKILL);
			return (1);
		}
		else if (game->pid_philo[i] == 0)
		{
			init_philo(game);
			routine(game);
		}
		i++;
	}
	sem_wait(game->stop);
	return (0);
}

void	kill_philo(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->philo_num)
	{
		kill(game->pid_philo[i], SIGKILL);
		i++;
	}
}

void	*eat_manager(void *g)
{
	t_game	*game;
	int		i;

	game = (t_game *)g;
	i = -1;
	sem_wait(game->print);
	while (++i < game->philo_num)
	{
		sem_post(game->print);
		sem_wait(game->full);
		sem_wait(game->print);
	}
	sem_post(game->stop);
	return (0);
}

void	*dead_manager(void *g)
{
	t_game		*game;
	long long	current;

	game = (t_game *)g;
	while (1)
	{
		current = get_time();
		if (current - game->philo.dead_time > game->lifetime)
		{
			sem_wait(game->print);
			printf("%lld %d %s\n", get_time() - game->time, \
			game->philo.id + 1, DEAD);
			sem_post(game->stop);
			exit(0);
		}
	}
	return (NULL);
}
