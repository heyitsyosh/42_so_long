/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:17:23 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/08 04:58:35 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	more_images_to_window(t_game *g, size_t y, size_t x)
{
	if (g->map[y][x] == PORTAL_FRONT)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->portal_front, x * WIDTH, y * HEIGHT);
	else if (g->map[y][x] == PORTAL_LEFT)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->portal_left, x * WIDTH, y * HEIGHT);
	else if (g->map[y][x] == PORTAL_RIGHT)
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->portal_right, x * WIDTH, y * HEIGHT);
}

void	images_to_window(t_game *g, size_t y, size_t x)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->wall, x * WIDTH, y * HEIGHT);
	else if (g->map[y][x] == '0')
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->empty, x * WIDTH, y * HEIGHT);
	else if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->coin_front, x * WIDTH, y * HEIGHT);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->exit, x * WIDTH, y * HEIGHT);
	else if (g->map[y][x] == 'P')
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->p_front, x * WIDTH, y * HEIGHT);
	else if (g->map[y][x] == 'L')
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->p_left, x * WIDTH, y * HEIGHT);
	else if (g->map[y][x] == 'R')
		mlx_put_image_to_window(g->mlx_id, g->win_id,
			g->i->p_right, x * WIDTH, y * HEIGHT);
	else
		more_images_to_window(g, y, x);
}

int	put_full_map(t_game *g)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			images_to_window(g, y, x);
			x++;
		}
		y++;
	}
	put_steps_on_screen(g);
	return (0);
}

void	start_game(t_game *g)
{
	g->mlx_id = mlx_init();
	if (!g->mlx_id)
	{
		free_map(g);
		print_err_and_exit("mlx connection failure");
	}
	g->win_id = mlx_new_window(g->mlx_id, WIDTH * g->map_width,
			HEIGHT * g->map_height, "so_long");
	g->i = malloc(sizeof(t_image));
	if (!g->win_id || !g->i)
	{
		free_map(g);
		free(g->i);
		free(g->mlx_id);
		print_err_and_exit("mlx window failure");
	}
	make_images(g);
	make_more_images(g);
	make_enemy_images(g);
	put_full_map(g);
}
