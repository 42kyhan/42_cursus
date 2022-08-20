/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:28:55 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/20 21:28:56 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	init_sem(t_game *game)
{
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("stop");
	sem_unlink("full");
	game->fork = sem_open("fork", O_CREAT | O_EXCL, S_IRWXU, game->philo_num);
	game->print = sem_open("print", O_CREAT | O_EXCL, S_IRWXU, 1);
	game->stop = sem_open("stop", O_CREAT | O_EXCL, S_IRWXU, 0);
	game->full = sem_open("full", O_CREAT | O_EXCL, S_IRWXU, 0);
}

void	init_manager(t_game *game)
{
	if (game->eatcount)
	{
		pthread_create(&game->manager, NULL, &eat_manager, game);
		pthread_detach(game->manager);
	}
}

void	init_philo(t_game *game)
{
	game->philo.dead_time = get_time();
	pthread_create(&game->manager, NULL, &dead_manager, game);
	pthread_detach(game->manager);
}
