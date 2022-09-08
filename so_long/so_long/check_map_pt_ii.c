/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_pt_ii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:42:10 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/08 21:58:47 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_map_error_and_exit(char *error_msg, t_game *info)
{
	size_t	i;

	ft_printf("Error\n%s", error_msg);
	i = 0;
	if (info->map)
		while (info->map[i] != NULL)
			free(info->map[i++]);
	free(info->map);
	exit(EXIT_SUCCESS);
}

bool	check_if_rectangle(t_game *info)
{
	if (info->map_height == info->map_width)
		return (false);
	return (true);
}

bool	check_for_walls(char **map, t_game *info)
{
	size_t	i;

	i = 0;
	while (**map != '\0')
		if (**map++ != '1')
			return (false);
	while (*map || i != info->map_height)
	{
		if (*map[0] != '1' && *map[info->map_width] != '1')
			return (false);
		i++;
		map++;
	}
	while (**map != '\0')
		if (**map++ != '1')
			return (false);
}
