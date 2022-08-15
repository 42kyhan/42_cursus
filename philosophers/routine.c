/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:14:00 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/15 15:17:30 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	routine_cnt(t_game *game, int i)
{
	while (game->dead == OFF && game->eatcount > game->philo[i].eat_cnt)
	{
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
	while (game->dead == OFF)
	{
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
	i = game->index;
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
		while (game->dead == OFF && game->eatcount > game->philo[i].eat_cnt)
			philo_dead(game, &i);
	else
		while (game->dead == OFF)
			philo_dead(game, &i);
	return (0);
}
