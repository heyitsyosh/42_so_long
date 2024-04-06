/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:34:57 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/07 06:32:15 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static void	make_more_enemy_images(t_game *g)
{
	int	x;
	int	y;

	g->i->s_r_i = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_r_1.xpm", &x, &y);
	g->i->s_r_ii = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_r_2.xpm", &x, &y);
	g->i->s_r_iii = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_r_3.xpm", &x, &y);
	g->i->s_r_iv = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_r_4.xpm", &x, &y);
	g->i->s_r_v = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_r_5.xpm", &x, &y);
	g->i->s_r_vi = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_r_6.xpm", &x, &y);
	g->i->s_r_vii = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_r_7.xpm", &x, &y);
	g->i->s_r_viii = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_r_8.xpm", &x, &y);
}

void	make_enemy_images(t_game *g)
{
	int	x;
	int	y;

	g->i->s_l_i = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_l_1.xpm", &x, &y);
	g->i->s_l_ii = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_l_2.xpm", &x, &y);
	g->i->s_l_iii = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_l_3.xpm", &x, &y);
	g->i->s_l_iv = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_l_4.xpm", &x, &y);
	g->i->s_l_v = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_l_5.xpm", &x, &y);
	g->i->s_l_vi = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_l_6.xpm", &x, &y);
	g->i->s_l_vii = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_l_7.xpm", &x, &y);
	g->i->s_l_viii = mlx_xpm_file_to_image(g->mlx_id,
			"./images/enemy/snake_l_8.xpm", &x, &y);
	make_more_enemy_images(g);
}
