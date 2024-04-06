/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:34:57 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/07 06:28:02 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	make_images(t_game *g)
{
	int	x;
	int	y;

	g->i->coin_front = mlx_xpm_file_to_image(g->mlx_id,
			"./images/collectible/coin_front.xpm", &x, &y);
	g->i->coin_left = mlx_xpm_file_to_image(g->mlx_id,
			"./images/collectible/coin_left.xpm", &x, &y);
	g->i->coin_right = mlx_xpm_file_to_image(g->mlx_id,
			"./images/collectible/coin_right.xpm", &x, &y);
	g->i->coin_side = mlx_xpm_file_to_image(g->mlx_id,
			"./images/collectible/coin_side.xpm", &x, &y);
	g->i->empty = mlx_xpm_file_to_image(g->mlx_id,
			"./images/tiles/brown_path.xpm", &x, &y);
	g->i->wall = mlx_xpm_file_to_image(g->mlx_id,
			"./images/tiles/grass_wall.xpm", &x, &y);
	g->i->exit = mlx_xpm_file_to_image(g->mlx_id,
			"./images/tiles/portal_exit.xpm", &x, &y);
	g->i->p_front = mlx_xpm_file_to_image(g->mlx_id,
			"./images/player/front.xpm", &x, &y);
	g->i->p_left = mlx_xpm_file_to_image(g->mlx_id,
			"./images/player/left.xpm", &x, &y);
	g->i->p_right = mlx_xpm_file_to_image(g->mlx_id,
			"./images/player/right.xpm", &x, &y);
	g->i->portal_front = mlx_xpm_file_to_image(g->mlx_id,
			"./images/player/portal_front.xpm", &x, &y);
}

void	make_more_images(t_game *g)
{
	int	x;
	int	y;

	g->i->portal_left = mlx_xpm_file_to_image(g->mlx_id,
			"./images/player/portal_left.xpm", &x, &y);
	g->i->portal_right = mlx_xpm_file_to_image(g->mlx_id,
			"./images/player/portal_right.xpm", &x, &y);
	g->i->i_left = mlx_xpm_file_to_image(g->mlx_id,
			"./images/player/disappear/1_left.xpm", &x, &y);
	g->i->i_right = mlx_xpm_file_to_image(g->mlx_id,
			"./images/player/disappear/1_right.xpm", &x, &y);
	g->i->ii = mlx_xpm_file_to_image(g->mlx_id,
			"./images/player/disappear/2.xpm", &x, &y);
	g->i->iii = mlx_xpm_file_to_image(g->mlx_id,
			"./images/player/disappear/3.xpm", &x, &y);
	g->i->iv = mlx_xpm_file_to_image(g->mlx_id,
			"./images/player/disappear/4.xpm", &x, &y);
	g->i->v = mlx_xpm_file_to_image(g->mlx_id,
			"./images/player/disappear/5.xpm", &x, &y);
	g->i->vi = mlx_xpm_file_to_image(g->mlx_id,
			"./images/player/disappear/6.xpm", &x, &y);
	g->i->vii = mlx_xpm_file_to_image(g->mlx_id,
			"./images/player/disappear/7.xpm", &x, &y);
	g->i->viii = mlx_xpm_file_to_image(g->mlx_id,
			"./images/player/disappear/8.xpm", &x, &y);
}

bool	check_if_images_created(t_image *images)
{
	if (!images->coin_front || !images->coin_left || !images->coin_right
		|| !images->coin_side || !images->empty || !images->wall
		|| !images->exit || !images->p_front || !images->p_left
		|| !images->p_right || !images->portal_front || !images->portal_left
		|| !images->portal_right || !images->i_left || !images->i_right
		|| !images->ii || !images->iii || !images->iv || !images->v
		|| !images->vi || !images->vii || !images->viii)
		return (false);
	return (true);
}