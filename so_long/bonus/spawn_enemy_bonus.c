/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_enemy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 00:30:00 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/09 02:11:43 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include <stdio.h>

static void	check_adjacent(size_t y, size_t x, t_game *g)
{
	if (g->map[y][x] && ft_strchr("C0", g->map[y][x]))
	{
		g->enemy_spawned = true;
		if (g->map[y][x] == 'C')
			g->enemy_on_coin = true;
		g->map[y][x - 1] = 'S';
		g->enemy_x = x - 1;
		g->enemy_y = y;
		g->e_step = 1;
	}
	printf("g->map[%zu][%zu]", y, x-1);
	fflush(stdout);
}

void	spawn_enemy(t_game *g)
{
	size_t	y;
	size_t	x;

	y = 1;
	while (g->map[y])
	{
		x = 1;
		while (g->map[y][x] && !g->enemy_spawned)
		{
			if (ft_strchr("C0", g->map[y][x]))
				check_adjacent(y, x + 1, g);
			x++;
		}
		if (g->enemy_spawned)
			break ;
		y++;
	}
	if (!g->enemy_spawned)
		ft_printf("Enemy could not be spawned!\n");
	printf("\n");
	for (int i = 0; g->map[i]; i++)
		printf("[%s]\n", g->map[i]);
}
