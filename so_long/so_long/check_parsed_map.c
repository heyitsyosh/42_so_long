/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:42:10 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/11 03:47:55 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_num_of_cep(t_game *info)
{
	if (info->num_of_collectibles < 1 || info->num_of_exits != 1
		|| info->num_of_players != 1)
		return (false);
	return (true);
}

bool	check_if_rectangle(t_game *info)
{
	fflush(stdout);
	if (info->map_height == info->map_width)
		return (false);
	return (true);
}

bool	check_for_walls(t_game *info)
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
