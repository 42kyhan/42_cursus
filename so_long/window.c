/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:21:30 by hankyuhong        #+#    #+#             */
/*   Updated: 2022/08/08 17:19:44 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map(t_game *game)
{
	check_rec(game);
	check_wall(game);
	check_pce(game);
}

void	map_init(t_game *game, char *line)
{
	game->map.height = 0;
	game->map.width = ft_strlen(line);
	game->map.c_cnt = 0;
	game->map.p_cnt = 0;
	game->map.e_cnt = 0;
	game->map.enemy_cnt = 0;
	game->map.total_map = (char **)calloc(1, (sizeof(char *)));
}

void	map_read(t_game *game, int fd)
{
	char	*line;

	line = get_line(fd);
	if (line == NULL)
		return ;
	map_init(game, line);
	while (line)
	{
		game->map.height++;
		game->map.total_map = (char **)hk_realloc(game->map.total_map, \
		game->map.height - 1, game->map.height);
		game->map.total_map[game->map.height - 1] = line;
		line = get_line(fd);
	}
	valid_map(game);
}

void	hk_window(t_game *game, char **argv)
{
	int	fd;

	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		hk_error("Wrong argument", game);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		hk_error("FD ERROR !", game);
	map_read(game, fd);
}
