/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:26:04 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/07 06:26:59 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //exit, EXIT_SUCCESS
#include "ft_printf.h"
#include "so_long.h"
#include "libft.h"

void	print_err_and_exit(char *err_message)
{
	ft_printf("Error\n%s\n", err_message);
	exit(EXIT_SUCCESS);
}

void	check_args(int argc, char **argv)
{
	char	*pointer_to_dot;

	if (argc != 2)
		print_err_and_exit("invalid arguments");
	pointer_to_dot = ft_strrchr(argv[1], '.');
	if (!pointer_to_dot)
		print_err_and_exit("map does not use .ber");
	if (pointer_to_dot)
		if (ft_strcmp(pointer_to_dot, ".ber"))
			print_err_and_exit("map does not use .ber");
}
