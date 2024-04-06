/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:29:00 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/07 02:54:25 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //write
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		div;
	long	buf;
	int		tmp;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	buf = (long)n;
	div = 1;
	if (buf < 0)
	{
		write(fd, "-", 1);
		buf *= -1;
	}
	while (buf / 10 >= div)
		div *= 10;
	while (div != 0)
	{
		tmp = (buf / div) + '0';
		write(fd, &tmp, 1);
		buf %= div;
		div /= 10;
	}
}
