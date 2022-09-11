/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 03:35:38 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/11 18:15:34 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*before_after_map(char *line)
{
	const char	*map_chars = "10CEP";
	size_t		i;

	i = 0;
	while (*(line + i) && !ft_strchr(map_chars, *(line + i)))
		i++;
	if (!*(line + i))
		return (NULL);
	else
		return (line + i);
}

void	*parse_line(char *line, t_game *g, t_parse *p)
{
	size_t		i;
	const char	*map_chars = "10CEP";
	char		*current_char;

	p->l->map_start_ptr = before_after_map(line);
	i = 0;
	while (p->l->map_start_ptr && *(p->l->map_start_ptr + i))
	{
		current_char = ft_strchr(map_chars, *(line + i));
		if (!current_char)
			break ;
		else if (*current_char == 'C')
			g->num_of_collectibles++;
		else if (*current_char == 'E')
			g->num_of_exits++;
		else if (*current_char == 'P')
			g->num_of_players++;
		p->map_started = true;
		i++;
	}
	ft_substr(line, )
	if (!parse_rest_of_line(line + i))
		p->l->map_end_ptr = NULL;
	p->l->current_map_width = i;
	return (line + i);
}
