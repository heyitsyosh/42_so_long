/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:10:00 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/06 20:09:40 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	g;

	check_args(argc, argv);
	get_map(argv[1], &g);
	for (int i = 0; g.map[i]; i++)
	{
		printf("[%s]\n", g.map[i]);	
		fflush(stdout);
	}
	start_game(&g);
	mlx_hook(g.win_id, 2, 1L << 0, &process_pressed_key, &g);
	//mlx_hook(g.win_id, );
	//mlx_hook(g.win_id, );
	mlx_loop_hook(g.mlx_id, &animation, &g);
	mlx_loop(g.mlx_id);
}

	//mlx_loop_hook(data.mlx, loop_func, &data);
	// mlx_hook(game.win, 2, 1, move_image, &game);
	// mlx_hook(game.win, 33, 1L << 17, close_window, &game);
	// mlx_hook(game.win, 12, 32768L, map_remake, &game);
//2 12 17 9 33
	// mlx_hook(sys_info->graphic.win, EXPOSE, 1L << 15, &draw_map, sys_info);
	// mlx_hook(sys_info->graphic.win, DESTROY, 0L, &quit_game, sys_info);
	// mlx_hook(sys_info->graphic.win, FOCUSIN, 1L << 21, &draw_map, sys_info);