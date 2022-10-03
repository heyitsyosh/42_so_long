/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:08:12 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/03 19:57:22 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	*strrchr_from_ptr(char *end, char *start, int c)
{
	while (*end != (char)c)
		if (end-- == start)
			return (NULL);
	return (end);
}

void	skip_before_map(char *joined_line, t_parse *p, t_game *g)
{
	const char	*map_chars = "10CEP";
	size_t		i;

	i = 0;
	while (!ft_strchr(map_chars, joined_line[i]))
		i++;
	if (joined_line[i] == '\0')
	{
		g->map_error = NO_MAP;
		return ;
	}
	else
		p->map_start_ptr = strrchr_from_ptr(joined_line + i, joined_line, '\n');
	if (!p->map_start_ptr)
	{
		p->map_start_ptr = joined_line;
		p->col_offset = i;
	}
	else
	{
		p->map_start_ptr += 1;
		p->col_offset = (joined_line + i) - (p->map_start_ptr + 1);
	}
}

void	skip_after_map(t_parse *p, t_game *g)
{
	const char	*map_chars = "10CEP";
	size_t		i;

	i = 0;
	while (p->map_end_ptr[i] && !ft_strchr(map_chars, p->map_end_ptr[i]))
		i++;
	if (p->map_end_ptr[i] != '\0')
		g->map_error = INVALID_MAP_FORMATTING;
}
