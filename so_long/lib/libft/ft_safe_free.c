/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 05:04:18 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/07 04:35:32 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //free
#include "../../includes/libft.h"

void	ft_safe_free(char **pointer)
{
	if (*pointer)
	{
		free(*pointer);
		*pointer = NULL;
	}
}
