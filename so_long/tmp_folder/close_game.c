/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:03:06 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/04 18:15:20 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_images(t_game *g)
{
	
}

void	close_mlx(t_game *g)
{
	destroy_images(g);
	mlx_destroy_window(g->mlx_id, g->win_id);
	mlx_destroy_display(g->mlx_id);
	free(g->mlx_id);
}
