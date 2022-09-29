/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:59:30 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/29 22:41:08 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_l(t_line *l)
{
	l->pre = 0;
	l->mid = 0;
	l->post = 0;
}

size_t	skip_irrelevant(char *ptr, int call, t_line *l, t_parse *p)
{
	const char	*map_chars = "10CEP\n";
	size_t		i;

	i = 0;
	while (!ft_strchr(map_chars, ptr[i]))
		i++;
	if ((ptr[i] == '\n' && call == PRE) || !ptr[i])
		p->map_ended = true;
	l->total += i;
	return (i);
}

size_t	parse_map()
{
	
}

char	*parse_line(t_line *l, t_parse *p, t_game *g)
{
	l->pre = skip_irrelevant(p->map_start_ptr + l->total, PRE, l, p);
	l->mid = parse_map(p->map_start_ptr + l->total, );
	l->post = skip_irrelevant(p->map_start_ptr + l->total, POST, l, p);
	if (!p->map_ended)
		if (l->pre != p->col_offset || l->mid != g->map_width)
			g->map_error = INVALID_MAP_FORMATTING;
	return (ft_substr());
}

void	extract_map(t_parse *p, t_game *g)
{
	char	*current_ln;
	char	*extracted;
	t_line	l;

	l.total = 0;
	extracted = ft_strdup("");
	while (!p->map_ended)
	{
		init_l(&l);
		current_ln = parse_line(&l, p, g);
		extracted = ft_strjoin_with_free(extracted, current_ln, 1);
	}
	g->map = ft_split(extracted, '\n');
	if (!g->map)
		g->map_error = MALLOC_FAIL;
	free(extracted);
}
