/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_RL.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:03 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/08 15:34:44 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left_move(t_game *game)
{
	if (game->i >= 64)
	{
		game->flag = 0;
		game->i = 0;
		game->player.x -= 64;
		if (game->map.total_map[game->player.y / 64] \
		[game->player.x / 64] == 'a')
		{
			game->map.total_map[game->player.y / 64][game->player.x / 64] = 'c';
			game->player.collect++;
		}
		game->lock = OFF;
		game->e_flag = ON;
	}
}

void	move_left(t_game *game)
{
	game->e_flag = OFF;
	if (game->map.total_map[game->player.y / 64] \
	[(game->player.x - 64) / 64] == '1')
	{
		game->lock = OFF;
		return ;
	}
	draw_wall(game);
	draw_pce(game);
	game->l_sprite = game->l_sprite->next;
	game->i += 8;
	mlx_put_image_to_window(game->mlx, game->win, game->l_sprite->img, \
	game->player.x - game->i, game->player.y);
	move_left_move(game);
}

void	move_right_move(t_game *game)
{
	if (game->i >= 64)
	{
		game->flag = 0;
		game->i = 0;
		game->player.x += 64;
		if (game->map.total_map[game->player.y / 64] \
		[game->player.x / 64] == 'a')
		{
			game->map.total_map[game->player.y / 64][game->player.x / 64] = 'c';
			game->player.collect++;
		}
		game->lock = OFF;
		game->e_flag = ON;
	}
}

void	move_right(t_game *game)
{
	game->e_flag = OFF;
	if (game->map.total_map[game->player.y / 64] \
	[(game->player.x + 64) / 64] == '1')
	{
		game->lock = OFF;
		return ;
	}
	draw_wall(game);
	draw_pce(game);
	game->r_sprite = game->r_sprite->next;
	game->i += 8;
	mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, \
	game->player.x + game->i, game->player.y);
	move_right_move(game);
}
