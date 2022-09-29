/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:57:14 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/20 18:54:00 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_map_error_and_exit(char *error_msg, t_game *g)
{
	size_t	i;

	i = 0;
	ft_printf("Error\n%s", error_msg);
	if (g->map)
		while (g->map[i] != NULL)
			free(g->map[i++]);
	free(g->map);
	exit(EXIT_SUCCESS);
}

char	*free_and_ret(char **ptr, char *ret)
{
	if (ptr)
		free(*ptr);
	return (ret);
}

// static int	analyze_parsed(size_t i, t_game *g, t_parse *p)
// {
// 	if (p->l->current_map_width == 0 && p->map_started)
// 		p->map_ended = true;
// 	if (!p->after_map)
// 		return (INVALID_MAP_FORMATTING);
// 	if (p->map_ended == false)
// 	{
// 		if (g->map_width != 0)
// 			if (p->l->current_map_width != g->map_width)
// 				return (WRONG_MAP_SHAPE);
// 		g->map_width = p->l->current_map_width;
// 	}
// 	else if (m->irrelevant != g->map[i])
// 		return (INVALID_MAP_FORMATTING);
// 	return (MAP_OK);
// }

static int	parse_map(size_t i, t_game *g)
{
	t_parse	p;
	int		map_status;

	while (g->map[i] != NULL)
	{
		map_status = parse_line(g->map[i], g, &p);
		if (map_status == MAP_OK)
			map_status = analyze_parsed(i, g, &p);
		if (map_status != MAP_OK)
			return (map_status);
		i++;
		if (!p.map_ended && g->map[i])
			g->map_height = i - p.col_offset;
	}
	return (MAP_OK);
}

void	check_map_validity(t_game *g)
{
	int		parse_map_ret;

	if (g->map)
		parse_map_ret = parse_map(0, g);
	if (!g->map || parse_map_ret == MALLOC_FAIL)
		put_map_error_and_exit("memory allocation error", g);
	if (g->map_height == 0)
		print_err_and_exit("no map");
	else if (parse_map_ret == INVALID_MAP_FORMATTING)
		put_map_error_and_exit("invalid map formatting", g);
	else if (parse_map_ret == WRONG_MAP_SHAPE || !check_if_rectangle(g))
		put_map_error_and_exit("invalid map shape", g);
	else if (!check_num_of_cep(g))
		put_map_error_and_exit("bad number of player/exit/collectibles", g);
	else if (!check_for_walls(g))
		put_map_error_and_exit("walls do not surround map", g);
	// else if (!check_for_valid_path(g->map))
	// 	put_map_error_and_exit("map does not contain valid path to exit", g);
	else
		return ;
}
