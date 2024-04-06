/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:52:24 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/07 04:09:08 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	step_to_portal(char player, int y, int x, t_game *g)
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

char	set_non_player(t_game *g)
{
	if (ft_strchr("PLR", g->map[g->player_y][g->player_x]))
		return ('0');
	else
		return ('E');
}

void	move_player(int y, int x, t_game *g)
{
	if (g->player_moved)
	{
		g->player_x += x;
		g->player_y += y;
		g->total_steps++;
	}
}

char	get_player(char player, t_game *g)
{
	if (ft_strchr("PLR", g->map[g->player_y][g->player_x]))
		return (player);
	if (player == 'P')
		return (PORTAL_FRONT);
	else if (player == 'L')
		return (PORTAL_LEFT);
	else
		return (PORTAL_RIGHT);
}
