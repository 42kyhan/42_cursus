/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:01:39 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/11 08:04:05 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_heredoc(const char *limiter)
{
	char	*line;
	char	*limiter_nl;
	int		pipe_line[2];

	pipe(pipe_line);
	limiter_nl = ft_strjoin(limiter, "\n");
	while (1)
	{
		write(2, "kyhan ", 6);
		line = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(line, limiter_nl, ft_strlen(limiter_nl) + 1))
		{
			free(line);
			free(limiter_nl);
			break ;
		}
		write(pipe_line[1], line, ft_strlen(line));
		free(line);
	}
	close(pipe_line[1]);
	return (pipe_line[0]);
}
