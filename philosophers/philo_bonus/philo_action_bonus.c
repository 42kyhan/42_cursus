/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:29:14 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/20 21:29:16 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_eat(t_game *game)
{
	sem_wait(game->fork);
	sem_wait(game->fork);
	sem_wait(game->print);
	printf("%lld %d %s\n", get_time() - game->time, game->philo.id + 1, FORK);
	printf("%lld %d %s\n", get_time() - game->time, game->philo.id + 1, FORK);
	sem_post(game->print);
	sem_wait(game->print);
	printf("%lld %d %s\n", get_time() - game->time, game->philo.id + 1, EAT);
	sem_post(game->print);
	game->philo.dead_time = get_time();
	game->philo.eat_cnt++;
	if (game->philo.eat_cnt == game->eatcount)
		sem_post(game->full);
	vsleep(game->eattime);
	sem_post(game->fork);
	sem_post(game->fork);
}

void	philo_sleep(t_game *game)
{
	sem_wait(game->print);
	printf("%lld %d %s\n", get_time() - game->time, game->philo.id + 1, SLEEP);
	sem_post(game->print);
	vsleep(game->sleeptime);
	sem_wait(game->print);
	printf("%lld %d %s\n", get_time() - game->time, game->philo.id + 1, THINK);
	sem_post(game->print);
}
