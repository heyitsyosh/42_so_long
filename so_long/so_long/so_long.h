/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 07:48:07 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/20 19:25:48 by myoshika         ###   ########.fr       */
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

# define WRONG_MAP_SHAPE 1
# define INVALID_MAP_FORMATTING 2
# define MALLOC_FAIL 3
# define MAP_OK 4

# define WIDTH 48
# define HEIGHT 48
typedef struct s_game{
	char	**map;
	size_t	num_of_collectibles;
	size_t	num_of_players;
	size_t	num_of_exits;
	size_t	map_width;
	size_t	map_height;
	void	*mlx_id;
}	t_game;
typedef struct s_parse{
	bool	map_started;
	bool	map_ended;
	size_t	col_offset;
	size_t	row_offset;
	t_line	*l;
}	t_parse;
typedef struct s_line{
	size_t	i;
	size_t	current_map_width;
	char	*map_start_ptr;
	char	*map_end_ptr;
}	t_line;

void	check_args(int argc, char **argv);
void	read_map(char *map_file, t_game *info);
void	print_err_and_exit(char *err_message);

void	check_map_validity(t_game *info);
char	*free_and_ret(char **ptr, char *ret);
void	put_map_error_and_exit(char *error_msg, t_game *info);

bool	check_num_of_cep(t_game *info);
bool	check_if_rectangle(t_game *info);
bool	check_for_walls(t_game *info);

#endif