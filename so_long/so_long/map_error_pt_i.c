/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_pt_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:57:14 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/06 22:14:05 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_num_of_cep(t_game *info)
{
	if (info->num_of_collectibles < 1 || info->num_of_exits != 1
		|| info->num_of_players != 1)
		return (false);
	return (true);
}

static char	*parse_line_till_nl(char *line, t_game *info)
{
	size_t		i;
	const char	*map_chars = "10CEP";
	char		*current_char;

	i = 0;
	while (*(line + i))
	{
		current_char = ft_strchr(map_chars, *(line + i));
		if (!current_char)
			break ;
		else if (*current_char == 'C')
			info->num_of_collectibles++;
		else if (*current_char == 'E')
			info->num_of_exits++;
		else if (*current_char == 'P')
			info->num_of_players++;
		i++;
	}
	if (info->map_width != -1)
		if (info->map_width != i || info->map_width != i + 1)
			return (NULL);
	else
		info->map_width = i; //does i include the irrelevant character or not
	return (line + i);
}

static int	parse_map(char **map, t_game *info)
{
	char	*tmp;
	char	*ptr_to_nl;

	while (*map != NULL)
	{
		ptr_to_nl = parse_line_till_nl(*map, info);
		if (!ptr_to_nl)
			return (WRONG_MAP_SIZE);
		else if (*ptr_to_nl != '\n' || !(*ptr_to_nl == '\0' && !(*map)++))
			return (INVALID_MAP_FORMATTING);
		*ptr_to_nl = '\0';
		tmp = ft_strdup(*map);
		if (!tmp)
			return (MALLOC_FAIL);
		free(*map);
		*map = tmp;
		free(tmp);
		(*map)++;
	}
	return (true);
}

static void	init_struct(t_game *info)
{
	info->num_of_collectibles = 0;
	info->num_of_players = 0;
	info->num_of_exits = 0;
	info->map_width = -1;
}

void	check_map_validity(t_game *info)
{
	int		parse_map_ret;

	init_struct(info);
	if (info->map)
		parse_map_ret = parse_map(info->map, info);
	if (!info->map || parse_map_ret == MALLOC_FAIL)
		put_map_error_and_exit("memory allocation error", info);
	else if (parse_map_ret == WRONG_MAP_SIZE)
		put_map_error_and_exit("invalid map size", info);
	else if (parse_map_ret == INVALID_MAP_FORMATTING)
		put_map_error_and_exit("invalid map formatting", info);
	else if (!check_num_of_cep(info))
		put_map_error_and_exit("bad number of player/exit/collectibles", info);
	else if (!check_for_walls(info->map, info))
		put_map_error_and_exit("walls do not surround map", info);
	else if (!check_for_valid_path(info->map))
		put_map_error_and_exit("map does not contain valid path to exit", info);
	else
		return ;
}


/*

//check return char ** of split. does it include "". does it add "" at end if char sent ends with separator?
*/
