/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:10:46 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/03 17:27:42 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_map_error(t_game *g)
{
	size_t	i;

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
	i = 0;
	while (g->map[i])
	{
		free(g->map[i]);
		i++;
	}
	free(g->map);
	if (g->map_error == NO_WALLS)
		print_err_and_exit("no walls");
	if (g->map_error == NO_VALID_PATH)
		print_err_and_exit("map not playable");
}

static void	init_p_and_g(t_parse *p, t_game *g)
{
	g->num_of_collectibles = 0;
	g->num_of_players = 0;
	g->num_of_exits = 0;
	g->map_width = 0;
	g->map_height = 0;
	g->map_error = MAP_OK;
	p->map_ended = false;
	p->col_offset = 0;
}

static int	open_map(char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		print_err_and_exit("failed to open file");
	return (fd);
}

static char	*read_map_into_line(int fd)
{
	char	*line;
	char	*joined_line;

	joined_line = ft_strdup("");
	while (joined_line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		joined_line = ft_strjoin_with_free(joined_line, line, FREE_FIRST_PARAM);
		free(line);
	}
	if (!joined_line)
		print_err_and_exit("malloc error");
	return (joined_line);
}

void	get_map(char *map_file, t_game *g)
{
	int		fd;
	char	*joined_line;
	t_parse	p;

	fd = open_map(map_file);
	joined_line = read_map_into_line(fd);
	init_p_and_g(&p, g);
	if (g->map_error == MAP_OK)
		skip_before_map(joined_line, &p, g);
	if (g->map_error == MAP_OK)
		extract_map(&p, g);
	if (g->map_error == MAP_OK)
		skip_after_map(&p, g);
	free(joined_line);
	check_for_walls(g);
	//check_for_valid_path(g);
	if (g->map_error != MAP_OK)
		print_map_error(g);
}
