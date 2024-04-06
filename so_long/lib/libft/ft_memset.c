/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:53:41 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/07 02:54:51 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*uc_b;
	size_t			i;

	uc_b = b;
	i = 0;
	while (i < len)
	{
		*(uc_b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
