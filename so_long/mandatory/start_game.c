/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:17:23 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/07 02:37:57 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_initial_map(t_game *g)
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
	if (!g->win_id)
	{
		free_map(g);
		print_err_and_exit("mlx window failure");
	}
	g->i = malloc(sizeof(t_image));
	make_images(g);
	make_more_images(g);
	put_initial_map(g);
}
