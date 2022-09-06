/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_pt_ii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:42:10 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/06 22:07:47 by myoshika         ###   ########.fr       */
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

bool	check_for_valid_path(, info)
{
	
}

bool	check_for_walls(char **map, t_game *info)
{
	size_t	i;
	
	while (*map[i] != '\0')
		if (*map[i++] != '1')
}
