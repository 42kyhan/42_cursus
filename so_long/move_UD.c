/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_UD.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:00 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/08 15:30:47 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up_move(t_game *game)
{
	if (game->i >= 64)
	{
		game->flag = 0;
		game->i = 0;
		game->player.y -= 64;
		if (game->map.total_map[game->player.y / 64] \
		[game->player.x / 64] == 'a')
		{
			game->map.total_map[game->player.y / 64] \
			[game->player.x / 64] = 'c';
			game->player.collect++;
		}
		game->lock = OFF;
		game->e_flag = ON;
	}
}

void	move_up(t_game *game)
{
	game->e_flag = OFF;
	if (game->map.total_map[(game->player.y - 64) / 64] \
	[game->player.x / 64] == '1')
	{
		game->lock = OFF;
		return ;
	}
	draw_wall(game);
	draw_pce(game);
	game->i += 8;
	if (game->player.prev_move_status == RIGHT)
	{
		game->r_sprite = game->r_sprite->next;
		mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, \
		game->player.x, game->player.y - game->i);
	}
	else
	{
		game->l_sprite = game->l_sprite->next;
		mlx_put_image_to_window(game->mlx, game->win, game->l_sprite->img, \
		game->player.x, game->player.y - game->i);
	}
	move_up_move(game);
}

void	move_down_move(t_game *game)
{
	if (game->i >= 64)
	{
		game->flag = 0;
		game->i = 0;
		game->player.y += 64;
		if (game->map.total_map[game->player.y / 64] \
		[game->player.x / 64] == 'a')
		{
			game->map.total_map[game->player.y / 64] \
			[game->player.x / 64] = 'c';
			game->player.collect++;
		}
		game->lock = OFF;
		game->e_flag = ON;
	}
}

void	move_down(t_game *game)
{
	game->e_flag = OFF;
	if (game->map.total_map[(game->player.y + 64) / 64] \
	[game->player.x / 64] == '1')
	{
		game->lock = OFF;
		return ;
	}
	draw_wall(game);
	draw_pce(game);
	game->i += 8;
	if (game->player.prev_move_status == RIGHT)
	{
		game->r_sprite = game->r_sprite->next;
		mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, \
		game->player.x, game->player.y + game->i);
	}
	else
	{
		game->l_sprite = game->l_sprite->next;
		mlx_put_image_to_window(game->mlx, game->win, game->l_sprite->img, \
		game->player.x, game->player.y + game->i);
	}
	move_down_move(game);
}
