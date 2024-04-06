/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:20:20 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/07 02:55:21 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uc_s = s;

	while (n--)
	{
		if (*uc_s == (unsigned char)c)
			return ((void *)uc_s);
		uc_s++;
	}
	return (NULL);
}
