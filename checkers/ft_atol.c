/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 11:49:48 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/12/07 12:09:22 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

long		ft_atol(const char *str)
{
	long long	number;
	int			negative;

	number = 0;
	negative = 0;
	while (*str == ' ' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == '\t')
		++str;
	if (*str == '-' || *str == '+')
		negative = (*str++ == '-') ? 1 : 0;
	if (!(*str >= '0' && *str <= '9'))
		return (2147483648);
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10;
		number = number + *str++ - '0';
	}
	return ((negative) ? (long)number * -1 : (long)number);
}
