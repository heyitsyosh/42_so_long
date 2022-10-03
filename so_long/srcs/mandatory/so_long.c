/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:10:00 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/03 22:33:49 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	g;

	check_args(argc, argv);
	get_map(argv[1], &g);
	//open_game_window(&g);
	size_t i = 0;
	while (g.map[i])
	{
		printf("[%s]\n", g.map[i]);
		i++;
	}
}

	// init_mlx(&game);
	// describe_map(&game);
	// game.num_c = count_c(game.head);
	// set_start_location(game.head, &game.step_x, &game.step_y);
	// mlx_hook(game.win, 2, 1, move_image, &game);
	// mlx_hook(game.win, 33, 1L << 17, close_window, &game);
	// mlx_hook(game.win, 12, 32768L, map_remake, &game);
	// mlx_loop_hook(game.mlx, render_next_frame, &game);
	// mlx_loop(game.mlx);
