/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:50:32 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/06 19:24:11 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_disappear_first_frame(t_game *g)
{
	if (g->map[g->exit_y][g->exit_x] == PORTAL_RIGHT)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->i_right, (g->exit_x) * WIDTH, g->exit_y * HEIGHT);
	else
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->i_left, g->exit_x * WIDTH, g->exit_y * HEIGHT);
}

static void	put_disappear_frame(int frame, t_game *g)
{
	if (frame == 1000)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->ii, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == 1500)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->iii, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == 2000)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->iv, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == 2500)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->v, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == 3000)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->vi, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == 3500)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->vii, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == 4000)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->viii, g->exit_x * WIDTH, g->exit_y * HEIGHT);
}

static void	put_coin_frame(int frame, size_t y, size_t x, t_game *g)
{
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'C')
			{
				if (frame == 500)
					mlx_put_image_to_window(g->mlx_id, g->win_id,
						g->i->coin_right, x * WIDTH, y * HEIGHT);
				else if (frame == 1000)
					mlx_put_image_to_window(g->mlx_id, g->win_id,
						g->i->coin_side, x * WIDTH, y * HEIGHT);
				else if (frame == 1500)
					mlx_put_image_to_window(g->mlx_id, g->win_id,
						g->i->coin_left, x * WIDTH, y * HEIGHT);
				else if (frame == 2000)
					images_to_window(g, y, x);
			}
			x++;
		}
		y++;
	}
}

int	animation(t_game *g)
{
	static int	coin;
	static int	disappear;

	if (g->game_ended)
	{
		disappear++;
		if (disappear == 500)
			put_disappear_first_frame(g);
		if (disappear != 500 && disappear % 500 == 0)
			put_disappear_frame(disappear, g);
		if (disappear == 4500)
		{
			ft_printf("---SUCCESS---\n");
			close_game(g);
		}
	}
	else
	{
		coin++;
		if (coin % 500 == 0)
			put_coin_frame(coin, 0, 0, g);
		if (coin == 2000)
			coin = 0;
	}
	return (0);
}
