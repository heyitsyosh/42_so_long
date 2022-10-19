/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 02:09:44 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/20 06:35:12 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	*set_l_enemy_frame(int frame, t_game *g)
{
	if (frame == FRAMERATE)
		return (g->i->s_l_i);
	else if (frame == FRAMERATE * 2)
		return (g->i->s_l_ii);
	else if (frame == FRAMERATE * 3)
		return (g->i->s_l_iii);
	else if (frame == FRAMERATE * 4)
		return (g->i->s_l_iv);
	else if (frame == FRAMERATE * 5)
		return (g->i->s_l_v);
	else if (frame == FRAMERATE * 6)
		return (g->i->s_l_vi);
	else if (frame == FRAMERATE * 7)
		return (g->i->s_l_vii);
	else if (frame == FRAMERATE * 8)
		return (g->i->s_l_viii);
	return (NULL);
}

static void	*set_enemy_frame(int frame, t_game *g)
{
	if (g->e_step == 1)
	{
		if (frame == FRAMERATE)
			return (g->i->s_r_i);
		else if (frame == FRAMERATE * 2)
			return (g->i->s_r_ii);
		else if (frame == FRAMERATE * 3)
			return (g->i->s_r_iii);
		else if (frame == FRAMERATE * 4)
			return (g->i->s_r_iv);
		else if (frame == FRAMERATE * 5)
			return (g->i->s_r_v);
		else if (frame == FRAMERATE * 6)
			return (g->i->s_r_vi);
		else if (frame == FRAMERATE * 7)
			return (g->i->s_r_vii);
		else if (frame == FRAMERATE * 8)
			return (g->i->s_r_viii);
		else
			return (NULL);
	}
	else
		return (set_l_enemy_frame(frame, g));
}

static bool	delay_enemy_movement(int *delay, t_game *g)
{
	char	to_switch_with;

	to_switch_with = '0';
	if (*delay == FRAMERATE * 7)
	{
		if (g->enemy_on_coin)
			to_switch_with = 'C';
		if (g->map[g->enemy_y][g->enemy_x + g->e_step] == 'C')
			g->enemy_on_coin = true;
		else
			g->enemy_on_coin = false;
		g->map[g->enemy_y][g->enemy_x + g->e_step] = 'S';
		g->map[g->enemy_y][g->enemy_x] = to_switch_with;
		g->enemy_x += g->e_step;
		*delay = 0;
		return (true);
	}
	return (false);
}

static void	put_enemy_frames(int *delay, t_game *g)
{
	if (delay_enemy_movement(delay, g))
		images_to_window(g, g->enemy_y, g->enemy_x - g->e_step);
	mlx_put_image_to_window(g->mlx_id, g->win_id,
		g->i->enemy, g->enemy_x * WIDTH, g->enemy_y * HEIGHT);
}

void	move_enemy(int frame, t_game *g)
{
	static int	delay;

	delay++;
	if (!g->enemy_spawned)
		return ;
	if (frame % FRAMERATE == 0)
	{
		if (ft_strchr("ABDE1", g->map[g->enemy_y][g->enemy_x + g->e_step]))
			g->e_step *= -1;
		else if (ft_strchr("PLR", g->map[g->enemy_y][g->enemy_x + g->e_step]))
		{
			ft_printf("---YOU LOST---\n");
			close_game(g, 0);
		}
		g->i->enemy = set_enemy_frame(frame, g);
		put_enemy_frames(&delay, g);
	}
}
