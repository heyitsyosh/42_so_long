/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:17:23 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/07 23:50:01 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	put_full_map(g);
}
