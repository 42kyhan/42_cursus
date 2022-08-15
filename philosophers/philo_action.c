/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:07:51 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/15 15:07:51 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_game *game, int i)
{
	long long	eattime;

	if (i % 2 == 0)
	{
		eattime = get_time() + game->eattime;
		pthread_mutex_lock(&game->fork[game->philo[i].fork.right]);
		philo_print(game, game->philo[i].id, FORK);
		pthread_mutex_lock(&game->fork[game->philo[i].fork.left]);
		philo_print(game, game->philo[i].id, FORK);
	}
	else
	{
		eattime = get_time() + game->eattime;
		pthread_mutex_lock(&game->fork[game->philo[i].fork.left]);
		philo_print(game, game->philo[i].id, FORK);
		pthread_mutex_lock(&game->fork[game->philo[i].fork.right]);
		philo_print(game, game->philo[i].id, FORK);
	}
	philo_print(game, game->philo[i].id, EAT);
	vsleep(game->eattime);
	game->philo[i].dead_time = get_time();
	unlock_fork(game, i);
}

void	philo_sleep(t_game *game, int i)
{
	long long	wakeup;

	wakeup = get_time() + game->sleeptime;
	philo_print(game, game->philo[i].id, SLEEP);
	vsleep(game->sleeptime);
}

void	philo_think(t_game *game, int i)
{
	philo_print(game, game->philo[i].id, THINK);
}

void	philo_dead(t_game *game, int *i)
{
	long long	time;

	if (*i == game->philo_num)
		*i = 0;
	time = curr_time(game->philo[*i].dead_time);
	if (time > game->lifetime)
	{
		philo_print(game, game->philo[*i].id, DEAD);
		game->dead = ON;
	}
	i++;
}
