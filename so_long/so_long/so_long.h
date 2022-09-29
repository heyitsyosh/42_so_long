/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 07:48:07 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/30 00:08:24 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <stdlib.h>
#include <stdio.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"
# include "../lib/gnl/get_next_line.h"

# define MAP_OK 1
# define WRONG_MAP_SHAPE 2
# define INVALID_MAP_FORMATTING 3
# define MALLOC_FAIL 4
# define NO_MAP 5
# define WRONG_CEP 6

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
	int		map_error;
	void	*mlx_id;
}	t_game;

typedef struct s_parse{
	bool	map_ended;
	size_t	col_offset; //horizontal orientation
	size_t	current_map_width;
	char	*map_start_ptr;
	char	*map_end_ptr;
}	t_parse;

typedef struct s_line{
	size_t	pre;
	size_t	mid;
	size_t	post;
	size_t	total;
}	t_line;

void	check_args(int argc, char **argv);
void	get_map(char *map_file, t_game *g);

void	skip_before_map(char *joined_line, t_parse *p, t_game *g);
void	skip_after_map(t_parse *p, t_game *g);

// char	*free_and_ret(char **ptr, char *ret);
// void	put_map_error_and_exit(char *error_msg, t_game *info);

// bool	check_num_of_cep(t_game *info);
// bool	check_if_rectangle(t_game *info);
// bool	check_for_walls(t_game *info);

void	print_err_and_exit(char *err_message);

#endif