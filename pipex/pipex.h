/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:01:54 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/11 08:16:27 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

# define ON 1
# define OFF 0
# define BUFFER_SIZE 1024

typedef struct s_pipex
{
	int			input;
	int			output;
	int			here_doc;
	int			ac;
	char		**execve_argv;
	char		**split_execve_argv;
}				t_pipex;

/* libft1.c */
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

/* libft2.c */
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free(char **strs);
char	*ft_strchr(char *s, int c);

/* split.c */
char	**ft_split(char const *s, char c);

/* error.c */
void	p_error(char *str);

/* parse.c */
void	parse_argv(int argc, char **argv, t_pipex *p);

/* init.c */
void	init(t_pipex *p);

/* start_execve.c */
void	start_execve(t_pipex *p, char **env);

/* gnl.c */
char	*get_next_line(int fd);

/* get_heredoc.c */
int		get_heredoc(const char *limiter);

/* open.c */
void	open_outfile(int argc, char **argv, t_pipex *p);
void	open_infile(char **argv, t_pipex *p);

/* get_path.c */
char	*get_path(char *cmd, char **env);

#endif