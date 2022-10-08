/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 02:09:44 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/09 02:56:19 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	*set_l_enemy_frame(int frame, t_game *g)
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
	return (NULL);
}

static void	*set_enemy_frame(int frame, t_game *g)
{
	if (g->e_step == 1)
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
		else
			return (NULL);
	}
	else
		return (set_l_enemy_frame(frame, g));
}

static bool	delay_enemy_movement(int *delay, char to_switch_with, t_game *g)
{
	if (*delay == 7000)
	{
		g->map[g->enemy_y][g->enemy_x + g->e_step] = 'S';
		g->map[g->enemy_y][g->enemy_x] = to_switch_with;
		g->enemy_x += g->e_step;
		*delay = 0;
		return (true);
	}
	return (false);
}

static void	put_enemy_frames(int *delay, char to_switch_with, t_game *g)
{
	if (delay_enemy_movement(delay, to_switch_with, g))
		images_to_window(g, g->enemy_y, g->enemy_x - g->e_step);
	mlx_put_image_to_window(g->mlx_id, g->win_id,
		g->i->enemy, g->enemy_x * WIDTH, g->enemy_y * HEIGHT);
	if (to_switch_with == 'C')
		g->enemy_on_coin = false;
}

void	move_enemy(int frame, char to_switch_with, t_game *g)
{
	static int	delay;

	delay++;
	if (!g->enemy_spawned)
		return ;
	if (frame % 1000 == 0)
	{
		if (g->enemy_on_coin)
			to_switch_with = 'C';
		if (ft_strchr("ABDE1", g->map[g->enemy_y][g->enemy_x + g->e_step]))
			g->e_step *= -1;
		else if (ft_strchr("PLR", g->map[g->enemy_y][g->enemy_x + g->e_step]))
		{
			ft_printf("--YOU LOST---\n");
			close_game(g, 0);
		}
		g->i->enemy = set_enemy_frame(frame, g);
		put_enemy_frames(&delay, to_switch_with, g);
		if (g->map[g->enemy_y][g->enemy_x + g->e_step] == 'C')
			g->enemy_on_coin = true;
	}
}
