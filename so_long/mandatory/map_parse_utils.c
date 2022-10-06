/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:10:10 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/06 19:17:42 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	info_to_g(char chr, size_t i, t_game *g)
{
	if (chr == 'P')
	{
		g->num_of_players++;
		g->player_x = g->map_height;
		g->player_y = i;
	}
	else
	{
		g->num_of_exits++;
		g->exit_x = g->map_height;
		g->exit_y = i;
	}
}

void	free_map(t_game *g)
{
	size_t	i;

	i = 0;
	while (g->map[i])
	{
		free(g->map[i]);
		i++;
	}
	free(g->map);
}

void	print_map_error(t_game *g)
{
	if (g->map_error == WRONG_MAP_SHAPE)
		print_err_and_exit("wrong map shape");
	else if (g->map_error == INVALID_MAP_FORMATTING)
		print_err_and_exit("invalid map formatting");
	else if (g->map_error == MALLOC_FAIL)
		print_err_and_exit("malloc failure");
	else if (g->map_error == NO_MAP)
		print_err_and_exit("no map in file");
	else if (g->map_error == WRONG_CEP)
		print_err_and_exit("invalid number of player, exit, and collectibles");
	free_map(g);
	if (g->map_error == NO_WALLS)
		print_err_and_exit("no walls");
	if (g->map_error == NO_VALID_PATH)
		print_err_and_exit("map not playable");
}
