/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hk_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:12 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/08 14:25:50 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	hk_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		destroy_win(game);
	else if (keycode == KEY_A && game->lock == OFF)
		left(keycode, game);
	else if (keycode == KEY_D && game->lock == OFF)
		right(keycode, game);
	else if (keycode == KEY_S && game->lock == OFF)
		down(keycode, game);
	else if (keycode == KEY_W && game->lock == OFF)
		up(keycode, game);
	else
		game->player.move_status = NONE;
	return (0);
}
