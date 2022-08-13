#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define ON 1
# define OFF 0

# define ERROR -1

typedef	struct s_fork
{
	int			left;
	int			right;
}				t_fork;


typedef struct s_philo
{
	int			id;
	int			eat_cnt;
	pthread_t	thread_id;
	t_fork		fork;
}				t_philo;


typedef struct s_game
{
	int				philo_num;
	int				lifetime;
	int				eattime;
	int				sleeptime;
	int				eatcount;
	int				eatcount_flag;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	t_philo			*philo;
}					t_game;


/* parse.c */
void	parse(int argc, char **argv, t_game *p);

/* creat_thread.c */
int		create_thread(t_game *game);
void	destroy_thread(t_game *game);

/* routine.c */
void	*start_routine(void *args);

/* error.c */
void	philo_error(char *str);

/* init.c */
void	game_init(t_game *p);
void	fork_init(t_game *game);
void	philo_init(t_game *game);

/* libft.c */
int	ft_atoi(const char *str);
void	free_all(t_game *game);

#endif
