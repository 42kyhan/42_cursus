/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:07:20 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/16 23:08:36 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (n < 0 || ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
		|| n > INT_MAX)
		return (0);
	return (n);
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
	pthread_mutex_lock(&game->m_dead);
	if (game->dead == ON)
	{
		pthread_mutex_unlock(&game->m_dead);
		return ;
	}
	pthread_mutex_unlock(&game->m_dead);
	pthread_mutex_lock(&game->m_dead);
	if (game->dead == ON)
	{
		pthread_mutex_unlock(&game->m_dead);
		return ;
	}
	else
		printf("%lld %d %s\n", current, id + 1, print);
	pthread_mutex_unlock(&game->m_dead);
}
