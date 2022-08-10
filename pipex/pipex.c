#include "pipex.h"

int	main(int argc, char **argv)
{
	t_pipex	p;

	init(&p);
	parse_argv(argc, argv, &p);
	start_execve(&p);
}