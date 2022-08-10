#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>

# define ON 1
# define OFF 0

typedef struct	s_pipex
{
	int			input;
	int			output;
	int			here_doc;
	char		**execve_argv;
	char		**split_execve_argv;
}				t_pipex;


/* libft.c */
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

/* split.c */
char	**ft_split(char const *s, char c);

/* error.c */
void	p_error(char *str);

/* parse.c */
void	parse_argv(int argc, char **argv, t_pipex *p);

/* init.c */
void	init(t_pipex *p);

/* start_execve.c */
void	start_execve(t_pipex *p);

#endif