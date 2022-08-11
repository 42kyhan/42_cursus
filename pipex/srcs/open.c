/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:08:08 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/11 12:15:44 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_infile(char **argv, t_pipex *p)
{
	if (p->here_doc == OFF)
		p->input = open(argv[1], O_RDONLY);
	else
		p->input = get_heredoc(argv[2]);
	if (p->input < 0)
	{
		perror(strerror(errno));
		exit(1);
	}
}

void	open_outfile(int argc, char **argv, t_pipex *p)
{
	if (p->here_doc == OFF)
		p->output = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
	else
		p->output = open(argv[argc - 1], O_CREAT | O_APPEND | O_WRONLY, 0666);
	if (p->output < 0)
	{
		perror(strerror(errno));
		exit(1);
	}
}
