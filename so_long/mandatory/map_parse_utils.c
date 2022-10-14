/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:10:10 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/15 03:08:51 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	split_extracted_line(char *extracted, t_game *g)
{
	if (g->map_error == MAP_OK)
	{	
		g->map = ft_split(extracted, '\n');
		g->map_dup = ft_split(extracted, '\n');
		if (!g->map || !g->map_dup)
		{
			free_map(g->map);
			free_map(g->map_dup);
			g->map_error = MALLOC_FAIL;
		}
	}
}

void	info_to_g(char chr, size_t i, t_game *g)
{
	if (chr == 'P')
	{
		g->num_of_players++;
		g->player_y = g->map_height;
		g->player_x = i;
	}
	else
	{
		g->num_of_exits++;
		g->exit_y = g->map_height;
		g->exit_x = i;
	}
}

void	free_map(char **map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
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
	free_map(g->map);
	if (g->map_error == NO_WALLS)
		print_err_and_exit("no walls");
}
