/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:46:50 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/03 05:00:48 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdbool.h>
# include <stdarg.h>
# include "./libft.h"

typedef struct s_printfinfo
{
	size_t	i;
	char	fmt;	
	int		precision;
	int		width;
	bool	dash;
	char	padding;
	bool	sharp;
	char	sign;
}	t_info;

int		ft_printf(const char *input, ...);

size_t	get_info(const char *after_pct, t_info *info);

int		put_char(t_info *info, int chr);
int		put_str(t_info *info, const char *str, bool need_to_free_str);
int		put_unsigned(t_info *info, unsigned long long ull);
int		put_signed(t_info *info, char *num);
int		put_num(char *num, int num_len, int printed, t_info *info);

int		no_conversion(const char *input, t_info *info);

char	*ft_ulltoa(unsigned long long ull, int base, t_info *info);
int		print_str(const char *input, size_t len);
#endif
