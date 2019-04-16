/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:36:04 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/12/07 11:36:07 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	*ft_tabcpy(t_stack *a)
{
	int *tab;
	int i;

	i = 0;
	if (!(tab = malloc(sizeof(int) * a->size)))
		return (0);
	while (i < a->size)
	{
		tab[i] = a->stack[i];
		i++;
	}
	return (tab);
}
