/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:50:32 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/08 02:10:04 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
	if (frame == 2000)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->ii, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == 3000)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->iii, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == 4000)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->iv, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == 5000)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->v, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == 6000)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->vi, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == 7000)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->vii, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == 8000)
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
				if (frame == 1000)
					mlx_put_image_to_window(g->mlx_id, g->win_id,
						g->i->coin_right, x * WIDTH, y * HEIGHT);
				else if (frame == 2000)
					mlx_put_image_to_window(g->mlx_id, g->win_id,
						g->i->coin_side, x * WIDTH, y * HEIGHT);
				else if (frame == 3000)
					mlx_put_image_to_window(g->mlx_id, g->win_id,
						g->i->coin_left, x * WIDTH, y * HEIGHT);
				else if (frame == 4000)
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
		if (disappear == 1000)
			put_disappear_first_frame(g);
		if (disappear != 1000 && disappear % 1000 == 0)
			put_disappear_frame(disappear, g);
		if (disappear == 9000)
		{
			ft_printf("----SUCCESS----\n");
			close_game(g);
		}
	}
	else
	{
		coin++;
		if (coin % 1000 == 0)
			put_coin_frame(coin, 0, 0, g);
		if (coin == 5000)
			coin = 0;
	}
	return (0);
}
