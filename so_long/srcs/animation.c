/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:50:32 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/07 04:09:25 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "so_long.h"

static void	put_special_disappear_frame(int frame, t_game *g)
{
	if (frame == FRAMERATE * 9)
	{
		ft_printf("----SUCCESS----\n");
		close_game(g, 0);
	}
	else
	{
		if (g->map[g->exit_y][g->exit_x] == PORTAL_RIGHT)
			mlx_put_image_to_window(g->mlx_id, g->win_id,
				g->i->i_right, (g->exit_x) * WIDTH, g->exit_y * HEIGHT);
		else
			mlx_put_image_to_window(g->mlx_id, g->win_id,
				g->i->i_left, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	}
}

static void	put_disappear_frame(int frame, t_game *g)
{
	if (frame == FRAMERATE * 2)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->ii, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == FRAMERATE * 3)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->iii, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == FRAMERATE * 4)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->iv, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == FRAMERATE * 5)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->v, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == FRAMERATE * 6)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->vi, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == FRAMERATE * 7)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->vii, g->exit_x * WIDTH, g->exit_y * HEIGHT);
	else if (frame == FRAMERATE * 8)
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
				if (frame == FRAMERATE)
					mlx_put_image_to_window(g->mlx_id, g->win_id,
						g->i->coin_right, x * WIDTH, y * HEIGHT);
				else if (frame == FRAMERATE * 2)
					mlx_put_image_to_window(g->mlx_id, g->win_id,
						g->i->coin_side, x * WIDTH, y * HEIGHT);
				else if (frame == FRAMERATE * 3)
					mlx_put_image_to_window(g->mlx_id, g->win_id,
						g->i->coin_left, x * WIDTH, y * HEIGHT);
				else if (frame == FRAMERATE * 4)
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
	static int	enemy;

	if (g->game_ended)
	{
		disappear++;
		if (disappear == FRAMERATE || disappear == FRAMERATE * 9)
			put_special_disappear_frame(disappear, g);
		if (disappear != FRAMERATE && disappear % FRAMERATE == 0)
			put_disappear_frame(disappear, g);
	}
	else
	{
		enemy++;
		move_enemy(enemy, g);
		if (enemy == FRAMERATE * 8)
			enemy = 0;
		coin++;
		if (coin % FRAMERATE == 0)
			put_coin_frame(coin, 0, 0, g);
		if (coin == FRAMERATE * 5)
			coin = 0;
	}
	return (0);
}
