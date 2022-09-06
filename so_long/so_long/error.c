/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:26:04 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/06 15:36:46 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err_and_exit(char *err_message)
{
	ft_printf("Error: %s", err_message);
	exit(EXIT_SUCCESS);
}

void	check_args(int argc, char **argv)
{
	char	*pointer_to_dot;

	if (argc != 2)
		print_err_and_exit("wrong arguments");
	if (!ft_strcmp(argv[0], "./so_long"))
		print_err_and_exit("wrong arguments");
	pointer_to_dot = ft_strchr(argv[1], '.');
	if (pointer_to_dot)
		if (!ft_strcmp(pointer_to_dot, ".ber"))
			print_err_and_exit("map does not use .ber");
}

bool	check_after_map()
{
	
}
//check return char ** of split. does it include "". does it add "" at end if char sent ends with separator?
bool	check_map_shape(char **map)
{
	size_t	first_line_len;
	size_t	current_line_len;

	first_line_len = ft_strlen(*map); //do i need to null guard?
	while (++(*map) != NULL)
	{
		current_line_len = ft_strlen(*map)
	}
	return (true);
}

void	check_map_validity(t_game *info)
{
	size_t	i;

	if (!info->map)
		ft_printf("Error: memory allocation error");
	else if (!check_map_shape(info->map))
		ft_printf("Error: invalid map shape");
	else if (!check_map_format(info->map))
		break ;
	else if (!check_for_valid_path(info->map))
		ft_printf("Error: map does not contain valid path to exit");
	else
		return ;
	i = 0;
	while (info->map[i] != NULL)
		free(info->map[i++]);
	free(info->map);
	exit(EXIT_SUCCESS);
}
