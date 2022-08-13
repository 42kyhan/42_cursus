#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game_init(&game);
	parse(argc, argv, &game);
	philo_init(&game);
	if (creat_thread(&game) == ERROR)
	{
		free_all(&game);
		philo_error("Fail to create thread");
	}
	destroy_tread(&game);
	free_all(&game);
}