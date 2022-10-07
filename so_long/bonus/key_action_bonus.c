/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:41:53 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/08 05:37:50 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	check_enemy(int y, int x, t_game *g)
{
	if (g->map[g->player_y + y][g->player_x + x] == 'S')
	{
		ft_printf("--YOU LOST---\n");
		close_game(g, 0);
	}
}

static void	update_map(char player, int y, int x, t_game *g)
{
	char	non_player;

	non_player = set_non_player(g);
	check_enemy(y, x, g);
	if (g->map[g->player_y + y][g->player_x + x] == '1')
		g->map[g->player_y][g->player_x] = get_player(player, g);
	else if (g->map[g->player_y + y][g->player_x + x] == 'E')
	{
		g->map[g->player_y][g->player_x] = non_player;
		step_to_portal(player, y, x, g);
		g->player_moved = true;
	}
	else
	{
		if (g->map[g->player_y + y][g->player_x + x] == 'C')
			g->num_of_collectibles--;
		g->map[g->player_y][g->player_x] = non_player;
		g->map[g->player_y + y][g->player_x + x] = player;
		g->player_moved = true;
	}
	images_to_window(g, g->player_y, g->player_x);
	images_to_window(g, g->player_y + y, g->player_x + x);
	move_player(y, x, g);
}

void	put_steps_on_screen(t_game *g)
{
	char	*steps;

	steps = ft_itoa(g->total_steps);
	if (!steps)
	{
		ft_printf("Error\nmalloc failure\n");
		close_game(g, 1);
	}
	images_to_window(g, 0, 0);
	images_to_window(g, 0, 1);
	images_to_window(g, 0, 2);
	mlx_string_put(g->mlx_id, g->win_id, 7, 15, 0x00004400, "Steps:");
	mlx_string_put(g->mlx_id, g->win_id, 45, 15, 0x00004400, steps);
	free(steps);
}

static void	decide_if_put_steps(t_game *g)
{
	if (g->total_steps > INT_MAX)
	{
		ft_printf("you took too many steps!\n");
		close_game(g, 0);
	}
	put_steps_on_screen(g);
	if (g->player_moved && g->total_steps > 0)
		ft_printf("Steps taken: %d\n", g->total_steps);
}

int	process_pressed_key(int keycode, t_game *g)
{
	if (keycode == ESC)
		close_game(g, 0);
	if (g->game_ended)
		return (0);
	g->player_moved = false;
	if (keycode == W)
		update_map('P', -1, 0, g);
	else if (keycode == A)
		update_map('L', 0, -1, g);
	else if (keycode == S)
		update_map('P', 1, 0, g);
	else if (keycode == D)
		update_map('R', 0, 1, g);
	decide_if_put_steps(g);
	return (0);
}
