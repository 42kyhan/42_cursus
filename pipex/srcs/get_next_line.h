/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:01:41 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/11 08:02:10 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
}	t_lst;

char	*get_next_line(int fd);
char	*make_line(t_lst **res_lst, size_t res_len, char *res);
t_lst	*read_line(int fd, t_lst **t_back, ssize_t *rd);
size_t	check_line(int fd, t_lst **res_lst, size_t *res_len);
size_t	check_enter_len(const char *s, int c, size_t *len);
void	*ft_lstfclean_g(t_lst **lst);
char	*ft_strdup_g(const char *s1);
size_t	ft_strlcat_g(char *dst, const char *src, size_t dstsize);
t_lst	*ft_lstnew_add_back(t_lst **lst, void *content);
t_lst	*ft_lstnew_g(void *content);

#endif