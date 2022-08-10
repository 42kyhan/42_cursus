#include "pipex.h"

void	init(t_pipex *p)
{
	p->input = 0;
	p->output = 0;
	p->here_doc = OFF;
}