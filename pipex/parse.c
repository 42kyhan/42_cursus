/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:01:49 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/11 12:10:37 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// void	check_off(char **argv, t_pipex *p)
// {
// 	p->input = open(argv[0], O_RDONLY);
// 	if (p->input < 0)
// 	{
// 		perror(strerror(errno));
// 		close(p->input);
// 		exit(1);
// 	}
// }

void	parse_argv(int argc, char **argv, t_pipex *p)
{
	if (argc <= 4)
	{
		perror("You have to enter at least 4 argument.");
		exit(1);
	}
	check_here_doc(argv[1], p);
	check_for_execve(argc, argv, p);
	open_infile(argv, p);
	open_outfile(argc, argv, p);
}
