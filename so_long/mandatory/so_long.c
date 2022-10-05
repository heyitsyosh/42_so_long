/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:10:00 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/05 20:23:43 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	g;

	check_args(argc, argv);
	get_map(argv[1], &g);
	start_game(&g);
	// mlx_hook(g.win_id, 2, );
	// mlx_hook(g.win_id, );
	// mlx_hook(g.win_id, );
	mlx_loop_hook(g.mlx_id, coin_animation, &g);
	mlx_loop(g.mlx_id);
}

	//mlx_loop_hook(data.mlx, loop_func, &data);
	// mlx_hook(game.win, 2, 1, move_image, &game);
	// mlx_hook(game.win, 33, 1L << 17, close_window, &game);
	// mlx_hook(game.win, 12, 32768L, map_remake, &game);
	// mlx_loop_hook(game.mlx, render_next_frame, &game);

	// mlx_hook(sys_info->graphic.win, KEY_PRESS, 1L << 0,
	// 		&proc_press_wasd_esc, sys_info);
	// mlx_hook(sys_info->graphic.win, EXPOSE, 1L << 15, &draw_map, sys_info);
	// mlx_hook(sys_info->graphic.win, DESTROY, 0L, &quit_game, sys_info);
	// mlx_hook(sys_info->graphic.win, FOCUSIN, 1L << 21, &draw_map, sys_info);