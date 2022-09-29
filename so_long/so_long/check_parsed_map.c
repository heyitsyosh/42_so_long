/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:42:10 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/29 21:31:55 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_num_of_cep(t_game *g)
{
	if (g->num_of_collectibles < 1 || g->num_of_exits != 1
		|| g->num_of_players != 1)
		g->map = WRONG_CEP;
}

void	check_if_rectangle(t_game *g)
{
	if (g->map_height == g->map_width)
		g->map_error = WRONG_MAP_SHAPE;
}

void	check_for_walls(t_game *info)
{
	size_t	i;

	i = 0;
	while (info->map[0][i] != '\0')
		if (info->map[0][i++] != '1')
			return (false);
	i = 1;
	while (info->map[i] && i < info->map_height - 1)
	{
		if (info->map[i][0] != '1' && info->map[i][info->map_width] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (info->map[info->map_height - 1][i] != '\0')
		if (info->map[info->map_height - 1][i++] != '1')
			return (false);
	return (true);
}
