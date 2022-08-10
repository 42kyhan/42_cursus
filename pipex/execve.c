#include "pipex.h"

void	multiple_pipe(t_pipex *p)
{
	int	fd[2];
}

void	here_doc(t_pipex *p)
{

}

void	start_execve(t_pipex *p)
{
	if (p->here_doc == OFF)
		mutiple_pipe(p);
	else if (p->here_doc == ON)
		here_doc(p);
}