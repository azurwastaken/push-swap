/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:10:30 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/12/07 12:10:32 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	swap(t_stack *stack)
{
	int tmp;

	if (stack && stack->stack)
	{
		if (stack->size >= 2)
		{
			tmp = stack->stack[0];
			stack->stack[0] = stack->stack[1];
			stack->stack[1] = tmp;
		}
	}
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	push(t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	if (a->size > 0)
	{
		while (i < b->size)
			i++;
		while (i > 0)
		{
			b->stack[i] = b->stack[i - 1];
			i--;
		}
		b->stack[0] = a->stack[0];
		b->size++;
		while (i + 1 < a->size)
		{
			a->stack[i] = a->stack[i + 1];
			i++;
		}
		a->size--;
	}
}
