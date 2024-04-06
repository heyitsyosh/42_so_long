/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:59:30 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/07 04:06:40 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //free
#include "get_next_line.h"
#include "so_long.h"
#include "libft.h"

static void	init_l(t_line *l)
{
	l->pre = 0;
	l->mid = 0;
	l->post = 0;
}

static size_t	skip_irrelevant(char *ptr, int call, t_parse *p)
{
	const char	*map_chars = "10CEP\n";
	size_t		i;

	i = 0;
	while (!ft_strchr(map_chars, ptr[i]))
		i++;
	if (!ptr[i] || (ptr[i] == '\n' && call == PRE))
	{
		p->map_ended = true;
		p->map_end_ptr = ptr + i;
	}
	return (i);
}

static size_t	parse_map(char *ptr, t_parse *p, t_game *g)
{
	const char	*map_chars = "10CEP";
	char		*current_char;
	size_t		i;

	i = 0;
	while (ptr[i])
	{
		current_char = ft_strchr(map_chars, ptr[i]);
		if (!current_char)
			break ;
		else if (*current_char == 'C')
			g->num_of_collectibles++;
		else if (*current_char == 'E')
			info_to_g(*current_char, i, g);
		else if (*current_char == 'P')
			info_to_g(*current_char, i, g);
		i++;
	}
	if (g->map_height == 0)
		g->map_width = i;
	else if (!p->map_ended)
		if (g->map_width != i)
			g->map_error = INVALID_MAP_FORMATTING;
	return (i);
}

static char	*parse_line(t_line *l, t_parse *p, t_game *g)
{
	l->pre = skip_irrelevant(l->current_ln, PRE, p);
	l->mid = parse_map(l->current_ln + l->pre, p, g);
	l->post = skip_irrelevant(l->current_ln + l->pre + l->mid, POST, p);
	if (*(l->current_ln + l->pre + l->mid + l->post) == '\n')
		l->post += 1;
	if (!p->map_ended)
		if (l->pre != p->col_offset || l->mid != g->map_width)
			g->map_error = INVALID_MAP_FORMATTING;
	if (l->mid)
		g->map_height++;
	return (ft_substr(l->current_ln + l->pre, 0, l->mid));
}

void	extract_map(t_parse *p, t_game *g)
{
	char	*current_ln;
	char	*extracted;
	t_line	l;

	l.current_ln = p->map_start_ptr;
	extracted = ft_strdup("");
	while (!p->map_ended && g->map_error == MAP_OK)
	{
		init_l(&l);
		current_ln = parse_line(&l, p, g);
		l.current_ln += l.pre + l.mid + l.post;
		extracted = ft_strjoin_with_free(extracted, current_ln, 1);
		free(current_ln);
		extracted = ft_strjoin_with_free(extracted, "\n", 1);
	}
	check_num_of_cep(g);
	check_basic_requirements(g);
	split_extracted_line(extracted, g);
	free(extracted);
}
