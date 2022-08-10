#include "pipex.h"

void	check_here_doc(char *argv, t_pipex *p)
{
	if (ft_strncmp(argv, "here_doc", ft_strlen(argv)) == 0)
		p->here_doc = ON;
}

void	check_for_execve(int argc, char **argv, t_pipex *p)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	if (p->here_doc == OFF)
	{
		p->execve_argv = (char **)malloc(sizeof(char *) * (argc - 2));
		i += 2;
	}
	else
	{
		p->execve_argv = (char **)malloc(sizeof(char *) * (argc - 3));
		i += 3;
	}
	while (i < argc - 1)
		p->execve_argv[a++] = argv[i++];
	p->execve_argv[a] = NULL;
}

void	check_off(char **argv, t_pipex *p)
{
	if (p->input = open(argv[0], O_RDONLY) < 0);
	{
		perror(strerror(errno));
		close(p->input);
		exit(1);
	}
}

void	check_on(char **argv, t_pipex *p)
{
	
}

void	parse_argv(int argc, char **argv, t_pipex *p)
{
	if (argc <= 4)
		perror("You have to enter at least 4 argument.");
	check_here_doc(argv[1], p);
	check_for_execve(argc, argv + 1, p);
	if (p->here_doc == OFF)
		check_off(argv + 1, p);
	else
		check_on(argv + 2, p);
}