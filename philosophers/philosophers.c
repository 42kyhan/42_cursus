/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:07:59 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/16 18:09:41 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	one_philo(t_game *game)
{
	pthread_mutex_init(&game->print, NULL);
	game->time = get_time();
	philo_print(game, 0, FORK);
	usleep(1000 * game->lifetime);
	philo_print(game, 0, DEAD);
	free_all(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game_init(&game);
	parse(argc, argv, &game);
	philo_init(&game);
	if (game.philo_num == 1)
	{
		one_philo(&game);
		return (0);
	}
	if (create_thread(&game) == ERROR)
	{
		free_all(&game);
		philo_error("Fail to create thread");
	}
	destroy_thread(&game);
	free_all(&game);
}
