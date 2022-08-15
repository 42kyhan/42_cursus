/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:07:30 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/15 15:07:30 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_parse(char **argv, t_game *game)
{
	game->philo_num = ft_atoi(argv[1]);
	game->lifetime = ft_atoi(argv[2]);
	game->eattime = ft_atoi(argv[3]);
	game->sleeptime = ft_atoi(argv[4]);
}

void	philo_with_eat_count_parse(char **argv, t_game *game)
{
	game->philo_num = ft_atoi(argv[1]);
	game->lifetime = ft_atoi(argv[2]);
	game->eattime = ft_atoi(argv[3]);
	game->sleeptime = ft_atoi(argv[4]);
	game->eatcount = ft_atoi(argv[5]);
	game->eatcount_flag = ON;
}

void	parse(int argc, char **argv, t_game *game)
{
	if (argc < 5 || argc > 6)
		philo_error("You can enter 4 or 5 arguments");
	if (argc == 5)
		philo_parse(argv, game);
	else if (argc == 6)
		philo_with_eat_count_parse(argv, game);
	if (game->philo_num == 1)
		philo_error("You have to more than 1 philosopher");
}
