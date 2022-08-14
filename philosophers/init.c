#include "philosophers.h"

void	game_init(t_game *game)
{
	game->eatcount = 0;
	game->eattime = 0;
	game->lifetime = 0;
	game->philo_num = 0;
	game->sleeptime = 0;
	game->eatcount_flag = OFF; 
	game->eat = 0;
	game->dead = 0;
}

void	fork_init(t_game *game)
{
	int	i;

	i = 0;
	game->fork = malloc(sizeof(pthread_mutex_t) * game->philo_num + 1);
	while (i < game->philo_num)
	{
		pthread_mutex_init(&(game->fork[i]), NULL);
		i++;
	}
}

void	philo_init(t_game *game)
{
	int	i;

	i = 0;
	game->philo = malloc(sizeof(t_philo) * game->philo_num + 1);
	while (i < game->philo_num)
	{
		game->philo[i].id = i;
		game->philo[i].fork.left = (i + 1) % game->philo_num;
		game->philo[i].fork.right = i;
		game->philo[i].eat_cnt = 0;
		i++;
	}
	fork_init(game);
}

void	unlock_fork(t_game *game, int i)
{
	pthread_mutex_unlock(&game->fork[game->philo[i].fork.left]);
	pthread_mutex_unlock(&game->fork[game->philo[i].fork.right]);
	game->philo[i].eat_cnt++;
}