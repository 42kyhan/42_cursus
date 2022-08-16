/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:07:51 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/16 23:25:38 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_game *game, int i)
{
	long long	eattime;

	if (i % 2 == 0)
	{
		pthread_mutex_lock(&game->fork[game->philo[i].fork.left]);
		philo_print(game, game->philo[i].id, FORK);
		pthread_mutex_lock(&game->fork[game->philo[i].fork.right]);
		philo_print(game, game->philo[i].id, FORK);
	}
	else
	{
		pthread_mutex_lock(&game->fork[game->philo[i].fork.right]);
		philo_print(game, game->philo[i].id, FORK);
		pthread_mutex_lock(&game->fork[game->philo[i].fork.left]);
		philo_print(game, game->philo[i].id, FORK);
	}
	philo_print(game, game->philo[i].id, EAT);
	pthread_mutex_lock(&game->print);
	game->philo[i].dead_time = get_time();
	pthread_mutex_unlock(&game->print);
	vsleep(game->eattime);
	unlock_fork(game, i);
}

void	philo_sleep(t_game *game, int i)
{
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

	if (*i == game->philo_num - 1)
		*i = 0;
	pthread_mutex_lock(&game->print);
	time = curr_time(game->philo[*i].dead_time);
	pthread_mutex_unlock(&game->print);
	if (time > game->lifetime)
	{
		philo_print(game, game->philo[*i].id, DEAD);
		pthread_mutex_lock(&game->m_dead);
		game->dead = ON;
		pthread_mutex_unlock(&game->m_dead);
	}
	(*i)++;
}
