/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:07:59 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/15 15:08:00 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game_init(&game);
	parse(argc, argv, &game);
	philo_init(&game);
	if (create_thread(&game) == ERROR)
	{
		free_all(&game);
		philo_error("Fail to create thread");
	}
	destroy_thread(&game);
	free_all(&game);
}
