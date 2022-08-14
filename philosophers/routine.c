#include "philosophers.h"

int	philo_eat(t_game *game, int i)
{
	if (i % 2 == 0)
	{
	pthread_mutex_lock(&game->fork[game->philo[i].fork.left]);
	philo_print(game, game->philo[i].id, FORK);
	pthread_mutex_lock(&game->fork[game->philo[i].fork.right]);
	philo_print(game, game->philo[i].id, FORK);
	}
	else
	{
		pthread_mutex_lock(&game->fork[game->philo[i].fork.right]);
		philo_print(game, game->philo[i].id, FORK);
		pthread_mutex_lock(&game->fork[game->philo[i].fork.left]);
		philo_print(game, game->philo[i].id, FORK);
	}
	philo_print(game, game->philo[i].id, EAT);
	game->philo[i].dead_time = get_time();
	usleep(game->eattime * 1000);
	unlock_fork(game, i);
	return (0);
}

void	philo_sleep(t_game *game, int i)
{
	philo_print(game, game->philo[i].id, SLEEP);
	usleep(game->sleeptime * 1000);
}

void	philo_think(t_game *game, int i)
{
	philo_print(game, game->philo[i].id, THINK);
}

void	*start_routine(void *args)
{
	t_game	*game;
	int		i;

	game = (t_game *)args;
	i = game->index;
	if (game->eatcount > 0)
	{
		while (game->dead == OFF && game->eatcount > game->philo[i].eat_cnt)
		{
			if (philo_eat(game, i))
				return (0);
			if (game->eatcount != game->philo[i].eat_cnt)
			{
				philo_sleep(game, i);
				philo_think(game, i);
			}
		}
	}
	else
	{
		while (game->dead == OFF)
		{
			if (philo_eat(game, i))
				return (0);
			if (game->eatcount != game->philo[i].eat_cnt)
			{
				philo_sleep(game, i);
				philo_think(game, i);
			}
		}
	}
	return (0);
}

void	philo_dead(t_game *game, int *i)
{
	long long	time;

	if (*i == game->philo_num)
		*i = 0;
	time = curr_time(game->philo[*i].dead_time);
	if (time > game->lifetime)
	{
		philo_print(game, game->philo[*i].id, DEAD);
		game->dead = ON;
	}
	i++;
}

void	*manage(void *args)
{
	t_game *game;
	int	i;

	game = (t_game *)args;
	i = 0;
	if (game->eatcount > 0)
	{
		while (game->dead == OFF && game->eatcount > game->philo[i].eat_cnt)
		{
			philo_dead(game, &i);
		}
	}
	else
	{
		while (game->dead == OFF)
		{
			philo_dead(game, &i);
		}
	}
	return (0);
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
		printf("%lld %d %s\n", current, id, print);
	pthread_mutex_unlock(&game->print);
}