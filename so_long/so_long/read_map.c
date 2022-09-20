/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:10:46 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/20 18:54:58 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_struct(t_game *info)
{
	info->num_of_collectibles = 0;
	info->num_of_players = 0;
	info->num_of_exits = 0;
	info->map_width = 0;
	info->map_height = 0;
}

static int	open_map(char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		print_err_and_exit("failed to open file");
	return (fd);
}

void	read_map(char *map_file, t_game *info)
{
	int		fd;
	char	*line;
	char	*joined_line;

	fd = open_map(map_file);
	joined_line = ft_strdup("");
	while (joined_line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		joined_line = ft_strjoin_with_free(joined_line, line, FREE_FIRST_PARAM);
		free(line);
	}
	init_struct(info);
	// info->map = ft_split(joined_line, '\n');
	// free(joined_line);
}
