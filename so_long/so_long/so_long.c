/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:10:00 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/10 22:22:52 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	info;

	check_args(argc, argv);
	read_map(argv[1], &info);
	check_map_validity(&info);
	//open_game_window(&info);
	size_t i = 0;
	while (info.map[i])
	{
		ft_printf("%s\n", info.map[i]);
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
