/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:29:45 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/20 21:30:11 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <string.h>
# include <signal.h>

# define ON 1
# define OFF 0

# define ERROR -1

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

# define INT_MAX 2147483647

typedef struct s_philo
{
	int			id;
	int			eat_cnt;
	long long	dead_time;
}				t_philo;

typedef struct s_game
{
	pid_t			*pid_philo;
	int				philo_num;
	int				lifetime;
	int				eattime;
	int				sleeptime;
	int				eatcount;
	int				eatcount_flag;
	long long		time;
	pthread_t		manager;
	sem_t			*fork;
	sem_t			*print;
	sem_t			*stop;
	sem_t			*full;
	t_philo			philo;
}					t_game;

/* parse_bonus.c */
int			parse(int argc, char **argv, t_game *p);

/* routine_bonus.c */
void		routine(t_game *game);
int			start_philo(t_game *game);
void		kill_philo(t_game *game);
void		*eat_manager(void *g);
void		*dead_manager(void *g);

/* philo_action_bonus.c */
void		philo_eat(t_game *game);
void		philo_sleep(t_game *game);

/* init_bonus.c */
void		init_manager(t_game *game);
void		init_sem(t_game *game);
void		init_philo(t_game *game);

/* libft_bonus.c */
int			ft_atoi(const char *str);
void		free_all(t_game *game);

/* get_time_bonus.c */
long long	get_time(void);
void		vsleep(unsigned int time);

#endif
