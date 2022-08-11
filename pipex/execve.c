/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:01:36 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/11 13:29:33 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(t_pipex *p, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(p->execve_argv[p->ac], ' ');
	p->ac++;
	if (ft_strncmp(cmd[0], "/", 1) == 0)
		path = cmd[0];
	else
		path = get_path(cmd[0], env);
	execve(path, cmd, env);
	perror(strerror(errno));
}

void	multiple_pipe(t_pipex *p, char **env, int *infile)
{
	int		pipefd[2];
	pid_t	pid;

	pipe(pipefd);
	pid = fork();
	if (pid == -1)
	{
		perror(strerror(errno));
		close(p->input);
		exit(1);
	}
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(*infile, STDIN_FILENO);
		close(*infile);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		exec(p, env);
	}
	close (pipefd[1]);
	close(*infile);
	*infile = pipefd[0];
}

void	final(t_pipex *p, char **env, int infile)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror(strerror(errno));
		close(p->input);
		exit(1);
	}
	if (pid == 0)
	{
		dup2(infile, STDIN_FILENO);
		close(infile);
		dup2(p->output, STDOUT_FILENO);
		close(p->output);
		exec(p, env);
	}
	close(infile);
	close(p->output);
	while (p->ac--)
		wait(NULL);
}

void	start_execve(t_pipex *p, char **env)
{
	int	infile;

	infile = p->input;
	while (p->execve_argv[p->ac + 1])
	{
		multiple_pipe(p, env, &infile);
		p->ac++;
	}
	final(p, env, infile);
}
