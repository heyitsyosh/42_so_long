/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:17:23 by myoshika          #+#    #+#             */
/*   Updated: 2023/01/14 01:12:38 by myoshika         ###   ########.fr       */
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
		print_err_and_exit("mlx connection failure");
	g->win_id = mlx_new_window(g->mlx_id, WIDTH * g->map_width,
			HEIGHT * g->map_height, "so_long");
	g->i = malloc(sizeof(t_image));
	if (!g->win_id || !g->i)
		print_err_and_exit("mlx window failure");
	make_images(g);
	make_more_images(g);
	if (!check_if_images_created(g->i))
		print_err_and_exit("image creation failure");
	put_full_map(g);
}
