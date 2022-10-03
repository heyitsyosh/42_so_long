/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 07:48:07 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/03 22:40:50 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
#include <stdio.h>
# include "../lib/mlx/mlx.h"
# include "./libft.h"
# include "./ft_printf.h"
# include "./get_next_line.h"

# define MAP_OK 1
# define WRONG_MAP_SHAPE 2
# define INVALID_MAP_FORMATTING 3
# define MALLOC_FAIL 4
# define NO_MAP 5
# define WRONG_CEP 6
# define NO_WALLS 7
# define NO_VALID_PATH 8

# define PRE 1
# define POST 2

# define WIDTH 48
# define HEIGHT 48

typedef struct s_game{
	char	**map;
	size_t	num_of_collectibles;
	size_t	num_of_players;
	size_t	num_of_exits;
	size_t	map_width;
	size_t	map_height;
	size_t	player_x;
	size_t	player_y;
	int		map_error;
	void	*mlx_id;
}	t_game;

typedef struct s_parse{
	bool	map_ended;
	size_t	col_offset;
	char	*map_start_ptr;
	char	*map_end_ptr;
}	t_parse;

typedef struct s_line{
	char	*current_ln;
	size_t	pre;
	size_t	mid;
	size_t	post;
}	t_line;

void	check_args(int argc, char **argv);
void	get_map(char *map_file, t_game *g);

void	skip_before_map(char *joined_line, t_parse *p, t_game *g);
void	skip_after_map(t_parse *p, t_game *g);
void	extract_map(t_parse *p, t_game *g);

void	check_num_of_cep(t_game *info);
void	check_if_rectangle(t_game *info);
void	check_for_walls(t_game *g);
void	check_basic_requirements(t_game *g);

void	print_err_and_exit(char *err_message);

#endif