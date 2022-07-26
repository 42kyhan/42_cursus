/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:17:40 by kyhan             #+#    #+#             */
/*   Updated: 2022/05/29 21:11:26 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		index;

	index = 0;
	if (!buffer[index])
		return (NULL);
	while (buffer[index] != '\0' && buffer[index] != '\n')
		index++;
	line = malloc(sizeof(char) * (index + 2));
	if (line == 0)
		return (0);
	index = 0;
	while (buffer[index] != '\0' && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	if (buffer[index] == '\n')
	{
		line[index] = '\n';
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*ft_save(char *buffer)
{
	int		i;
	int		j;
	char	*backup;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (0);
	}
	backup = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (backup == 0)
		return (0);
	i++;
	while (buffer[i] != '\0')
		backup[j++] = buffer[i++];
	backup[j] = '\0';
	free(buffer);
	return (backup);
}

char	*ft_read(int fd, char *buffer)
{
	char	*buf;
	int		return_value;

	return_value = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == 0)
		return (0);
	while (!ft_strchr(buffer, '\n') && return_value != 0)
	{
		return_value = read(fd, buf, BUFFER_SIZE);
		if (return_value == -1)
		{
			free(buf);
			return (0);
		}
		buf[return_value] = '\0';
		buffer = ft_strjoin(buffer, buf);
	}
	free(buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX < fd)
		return (0);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (buffer[fd] == 0)
		return (0);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_save(buffer[fd]);
	return (line);
}
