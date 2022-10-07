/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 02:09:44 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/08 05:58:51 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	*set_enemy_frame(int frame, t_game *g)
{
	if (frame == 1000)
		return (g->i->s_l_i);
	else if (frame == 2000)
		return (g->i->s_l_ii);
	else if (frame == 3000)
		return (g->i->s_l_iii);
	else if (frame == 4000)
		return (g->i->s_l_iv);
	else if (frame == 5000)
		return (g->i->s_l_v);
	else if (frame == 6000)
		return (g->i->s_l_vi);
	else if (frame == 7000)
		return (g->i->s_l_vii);
	else if (frame == 8000)
		return (g->i->s_l_viii);
}

static void	*set_enemy_frame(int frame, t_game *g)
{
	if (g->enemy_step == 1)
	{
		if (frame == 1000)
			return (g->i->s_r_i);
		else if (frame == 2000)
			return (g->i->s_r_ii);
		else if (frame == 3000)
			return (g->i->s_r_iii);
		else if (frame == 4000)
			return (g->i->s_r_iv);
		else if (frame == 5000)
			return (g->i->s_r_v);
		else if (frame == 6000)
			return (g->i->s_r_vi);
		else if (frame == 7000)
			return (g->i->s_r_vii);
		else if (frame == 8000)
			return (g->i->s_r_viii);
	}
	else
		return (set_l_enemy_frame(frame, g));
}

void	move_enemy(int frame, t_game *g)
{
	char	*obstacle;

	if (frame % 1000 == 0)
	{
		if (ft_strchr("ABDE1", g->map[g->enemy_y][g->enemy_x + g->enemy_step]))
			g->enemy_step *= -1;
		g->i->enemy = set_enemy_frame(frame, g);
		g->map[g->enemy_y][g->enemy_x + g->enemy_step] = 'S';
		g->map[g->enemy_y][g->enemy_x] = '0';
		images_to_window(g, g->player_y, g->player_x);
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->enemy, g->enemy_y * WIDTH, g->enemy_x * HEIGHT);
		g->enemy_x += g->enemy_step;
	}
}
