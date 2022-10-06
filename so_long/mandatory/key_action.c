/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:41:53 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/07 04:51:58 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	step_to_portal(char player, int y, int x, t_game *g)
{
	if (player == 'P')
		g->map[g->player_y + y][g->player_x + x] = PORTAL_FRONT;
	else if (player == 'L')
		g->map[g->player_y + y][g->player_x + x] = PORTAL_LEFT;
	else if (player == 'R')
		g->map[g->player_y + y][g->player_x + x] = PORTAL_RIGHT;
	if (g->num_of_collectibles == 0)
		g->game_ended = true;
}

static char	set_non_player(t_game *g)
{
	if (ft_strchr("PLR", g->map[g->player_y][g->player_x]))
		return ('0');
	else
		return ('E');
}

static void	move_player(int y, int x, t_game *g)
{
	if (g->player_moved)
	{
		g->player_x += x;
		g->player_y += y;
	}
}

static void	update_map(char player, int y, int x, t_game *g)
{
	char	non_player;

	non_player = set_non_player(g);
	if (g->map[g->player_y + y][g->player_x + x] == '1')
	{
		g->map[g->player_y][g->player_x] = player;
		g->player_moved = false;
	}
	else if (g->map[g->player_y + y][g->player_x + x] == 'E')
	{
		g->map[g->player_y][g->player_x] = non_player;
		step_to_portal(player, y, x, g);
	}
	else
	{
		if (g->map[g->player_y + y][g->player_x + x] == 'C')
			g->num_of_collectibles--;
		g->map[g->player_y][g->player_x] = non_player;
		g->map[g->player_y + y][g->player_x + x] = player;
	}
	images_to_window(g, g->player_y, g->player_x);
	images_to_window(g, g->player_y + y, g->player_x + x);
	move_player(y, x, g);
}

int	process_pressed_key(int keycode, t_game *g)
{
	if (keycode == ESC)
		close_game(g);
	if (g->game_ended)
		return (0);
	g->player_moved = true;
	if (keycode == W)
		update_map('P', -1, 0, g);
	else if (keycode == A)
		update_map('L', 0, -1, g);
	else if (keycode == S)
		update_map('P', 1, 0, g);
	else if (keycode == D)
		update_map('R', 0, 1, g);
	return (0);
}
