#include "philosophers.h"

int		create_thread(t_game *game)
{
	int	i;

	i = 0;
	pthread_mutex_init(&game->print, NULL);
	while (i < game->philo_num)
	{
		if (pthread_create(&game->philo[i].thread_id, NULL, &start_routine, game))
			return (ERROR);
		i++;
	}
	i = 0;
	while (i < game->philo_num)
	{
		if (pthread_join(game->philo[i].thread_id, NULL))
			return (ERROR);
		i++;
	}
	return (0);
}

void	destroy_thread(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->philo_num)
	{
		pthread_mutex_destroy(&game->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&game->print);
}