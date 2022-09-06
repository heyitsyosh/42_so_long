/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:10:46 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/06 14:53:14 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../lib/gnl/get_next_line.h"

int	open_map(char *map_file)
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
	size_t	line_count;
	char	*line;
	char	*joined_line;

	fd = open_map(map_file);
	joined_line = ft_strdup("");
	line_count = 0;
	while (joined_line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		joined_line = ft_strjoin_with_free(joined_line, line, FREE_FIRST_PARAM);
		line_count++;
		free(line);
	}
	if (joined_line == NULL)
		print_err_and_exit("memory allocation error");
	info->map = ft_split(joined_line, "\n");
}
