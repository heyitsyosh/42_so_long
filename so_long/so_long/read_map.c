/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:10:46 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/22 16:05:10 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_t_game(t_game *g)
{
	g->num_of_collectibles = 0;
	g->num_of_players = 0;
	g->num_of_exits = 0;
	g->map_width = 0;
	g->map_height = 0;
}

static void	init_t_parse(t_parse *p)
{
	p->map_started = false;
	p->map_ended = false;
	// p->col_offset = 0;
	// p->row_offset = 0;
}

static int	open_map(char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		print_err_and_exit("failed to open file");
	return (fd);
}

char *skip_before_map(t_parse *p, )
{
	
}

void	read_map(char *map_file, t_game *g)
{
	int		fd;
	int		line_status;
	char	*line;
	char	*joined_line;
	t_parse	p;

	fd = open_map(map_file);
	joined_line = ft_strdup("");
	init_t_game(g);
	init_t_parse(&p);
	skip_before_map();
	while (joined_line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_status = parse_line(line, g, p);
		line = extract_line();
		joined_line = ft_strjoin_with_free(joined_line, line, FREE_FIRST_PARAM);
		free(line);
	}
	skip_after_map();
}

/*

if (line_status == FIRST_LINE)
			put_in_first_line_info();
		else if (line_status != MAP_OK)
			map_error_and_exit(line_status, joined_line, line);
		line = free_and_ret(&line, ft_substr(line, ))
		joined_line
		*/