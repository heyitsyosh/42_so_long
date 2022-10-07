/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:03:06 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/08 05:30:45 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_images(t_game *g)
{
	mlx_destroy_image(g->mlx_id, g->i->coin_front);
	mlx_destroy_image(g->mlx_id, g->i->coin_left);
	mlx_destroy_image(g->mlx_id, g->i->coin_right);
	mlx_destroy_image(g->mlx_id, g->i->coin_side);
	mlx_destroy_image(g->mlx_id, g->i->empty);
	mlx_destroy_image(g->mlx_id, g->i->wall);
	mlx_destroy_image(g->mlx_id, g->i->exit);
	mlx_destroy_image(g->mlx_id, g->i->p_front);
	mlx_destroy_image(g->mlx_id, g->i->p_left);
	mlx_destroy_image(g->mlx_id, g->i->p_right);
	mlx_destroy_image(g->mlx_id, g->i->portal_front);
	mlx_destroy_image(g->mlx_id, g->i->portal_left);
	mlx_destroy_image(g->mlx_id, g->i->portal_right);
	mlx_destroy_image(g->mlx_id, g->i->i_left);
	mlx_destroy_image(g->mlx_id, g->i->i_right);
	mlx_destroy_image(g->mlx_id, g->i->ii);
	mlx_destroy_image(g->mlx_id, g->i->iii);
	mlx_destroy_image(g->mlx_id, g->i->iv);
	mlx_destroy_image(g->mlx_id, g->i->v);
	mlx_destroy_image(g->mlx_id, g->i->vi);
	mlx_destroy_image(g->mlx_id, g->i->vii);
	mlx_destroy_image(g->mlx_id, g->i->viii);
}

int	close_game(t_game *g, int exit_status)
{
	free_map(g);
	destroy_images(g);
	mlx_destroy_window(g->mlx_id, g->win_id);
	mlx_destroy_display(g->mlx_id);
	free(g->mlx_id);
	free(g->i);
	exit(exit_status);
	return (0);
}
