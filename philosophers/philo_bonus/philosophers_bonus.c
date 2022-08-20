/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:07:59 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/20 21:28:31 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	one_philo(t_game *game)
{
	game->time = get_time();
	sem_wait(game->print);
	printf("%lld %d %s\n", get_time() - game->time, game->philo.id + 1, FORK);
	sem_post(game->print);
	usleep(1000 * game->lifetime);
	sem_wait(game->print);
	printf("%lld %d %s\n", get_time() - game->time, game->philo.id + 1, DEAD);
	sem_post(game->print);
	free_all(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (parse(argc, argv, &game))
		return (1);
	if (game.philo_num == 1)
	{
		one_philo(&game);
		exit(0);
	}
	start_philo(&game);
	kill_philo(&game);
	free_all(&game);
}
