/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:14:00 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/16 23:06:06 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	routine_cnt(t_game *game, int i)
{
	while (1)
	{
		pthread_mutex_lock(&game->m_dead);
		if (!(game->dead == OFF && game->eatcount > game->philo[i].eat_cnt))
		{
			pthread_mutex_unlock(&game->m_dead);
			break ;
		}
		pthread_mutex_unlock(&game->m_dead);
		philo_eat(game, i);
		if (game->eatcount != game->philo[i].eat_cnt)
		{
			philo_sleep(game, i);
			philo_think(game, i);
		}
	}
}

void	routine(t_game *game, int i)
{
	while (1)
	{
		pthread_mutex_lock(&game->m_dead);
		if (game->dead != OFF)
		{
			pthread_mutex_unlock(&game->m_dead);
			break ;
		}
		pthread_mutex_unlock(&game->m_dead);
		philo_eat(game, i);
		if (game->eatcount != game->philo[i].eat_cnt)
		{
			philo_sleep(game, i);
			philo_think(game, i);
		}
	}
}

void	*start_routine(void *args)
{
	t_game	*game;
	int		i;

	game = (t_game *)args;
	pthread_mutex_lock(&game->print);
	i = game->index;
	pthread_mutex_unlock(&game->print);
	if (game->eatcount > 0)
		routine_cnt(game, i);
	else
		routine(game, i);
	return (0);
}

void	*manage(void *args)
{
	t_game	*game;
	int		i;

	game = (t_game *)args;
	i = 0;
	if (game->eatcount > 0)
	{
		while (1)
		{
			pthread_mutex_lock(&game->m_dead);
			if (!(game->dead == OFF && game->eatcount > game->philo[i].eat_cnt))
			{
				pthread_mutex_unlock(&game->m_dead);
				break ;
			}
			pthread_mutex_unlock(&game->m_dead);
			philo_dead(game, &i);
		}
	}
	else
		while (game->dead == OFF)
			philo_dead(game, &i);
	return (0);
}
