/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:29:07 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/20 21:29:07 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	philo_parse(char **argv, t_game *game)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (ft_atoi(argv[i]) == 0)
		{
			printf("num error\n");
			return (1);
		}
		i++;
	}
	game->philo_num = ft_atoi(argv[1]);
	game->lifetime = ft_atoi(argv[2]);
	game->eattime = ft_atoi(argv[3]);
	game->sleeptime = ft_atoi(argv[4]);
	return (0);
}

int	philo_with_eat_count_parse(char **argv, t_game *game)
{
	int	i;

	i = 1;
	while (i < 6)
	{
		if (ft_atoi(argv[i]) == 0)
		{
			printf("num error\n");
			return (1);
		}
		i++;
	}
	game->philo_num = ft_atoi(argv[1]);
	game->lifetime = ft_atoi(argv[2]);
	game->eattime = ft_atoi(argv[3]);
	game->sleeptime = ft_atoi(argv[4]);
	game->eatcount = ft_atoi(argv[5]);
	game->eatcount_flag = ON;
	return (0);
}

int	parse(int argc, char **argv, t_game *game)
{
	memset(game, 0, sizeof(t_game));
	if (argc < 5 || argc > 6)
	{
		printf("You can enter 4 or 5 arguments\n");
		return (1);
	}
	if (argc == 5)
	{
		if (philo_parse(argv, game))
			return (1);
	}
	else if (argc == 6)
	{
		if (philo_with_eat_count_parse(argv, game))
			return (1);
	}
	game->pid_philo = malloc(sizeof(pid_t) * game->philo_num);
	memset(game->pid_philo, 0, sizeof(pid_t) * game->philo_num);
	init_sem(game);
	init_manager(game);
	return (0);
}
