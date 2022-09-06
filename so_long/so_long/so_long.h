/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 07:48:07 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/06 22:09:07 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <stdlib.h>

# define WRONG_MAP_SIZE 3
# define INVALID_MAP_FORMATTING 4
# define MALLOC_FAIL 5
typedef struct s_game{
	char	**map;
	size_t	num_of_collectibles;
	size_t	num_of_players;
	size_t	num_of_exits;
	size_t	map_width;
}	t_game;

#endif