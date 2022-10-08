/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:10:00 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/09 01:53:17 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	g;

	check_args(argc, argv);
	get_map(argv[1], &g);
	check_if_playable(&g);
	spawn_enemy(&g);
	start_game(&g);
	mlx_hook(g.win_id, 2, 1L << 0, &process_pressed_key, &g);
	mlx_hook(g.win_id, 12, 1L << 15, &put_full_map, &g);
	mlx_hook(g.win_id, 17, 0L, &close_game, &g);
	mlx_hook(g.win_id, 9, 1L << 21, &put_full_map, &g);
	mlx_loop_hook(g.mlx_id, &animation, &g);
	mlx_loop(g.mlx_id);
}
