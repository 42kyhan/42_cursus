/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:07:20 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/15 15:07:21 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int		res;
	int		minus;
	size_t	i;

	i = 0;
	res = 0;
	minus = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && (str[i] != '\0'))
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + minus * (str[i++] - 48);
		if (res > 0 && minus == -1)
			philo_error("Please enter int range");
		if (res < 0 && minus == 1)
			philo_error("Please enter int range");
	}
	return (res);
}

void	free_all(t_game *game)
{
	free(game->philo);
	free(game->fork);
}

void	philo_print(t_game *game, int id, char *print)
{
	long long	current;

	current = curr_time(game->time);
	if (game->dead == ON)
		return ;
	pthread_mutex_lock(&game->print);
	if (game->dead == ON)
	{
		pthread_mutex_unlock(&game->print);
		return ;
	}
	else
		printf("%lld %d %s\n", current, id + 1, print);
	pthread_mutex_unlock(&game->print);
}
