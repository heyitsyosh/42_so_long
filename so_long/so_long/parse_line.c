/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 03:35:38 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/20 18:56:56 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*parse_not_map_chars(char *line)
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

static char *parse_map_chars(char *line, t_game *g, t_parse *p)
{
	char		*current_char;
	const char	*map_chars = "10CEP";
	size_t		i;

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
	p->l->current_map_width = i;
}

void	*parse_line(char *line, t_game *g, t_parse *p)
{
	p->l->i = 0;
	p->l->map_start_ptr = parse_not_map_chars(line);
	if (p->l->map_start_ptr)
		parse_map_chars();
	ft_substr(line, i, )
	if (!parse_not_map_chars(line + i))
		p->l->map_end_ptr = NULL;
	p->l->current_map_width = i;
	return (line + i);
}
