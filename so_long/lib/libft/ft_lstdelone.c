/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:28:37 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/07 02:56:36 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //free
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!(lst == NULL || del == NULL))
		del(lst->content);
	free(lst);
}
