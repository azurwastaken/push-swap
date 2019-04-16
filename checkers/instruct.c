/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:10:30 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/12/07 12:10:32 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	rotate(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->size > 1)
	{
		i = 0;
		tmp = stack->stack[0];
		while (i + 1 < stack->size)
		{
			stack->stack[i] = stack->stack[i + 1];
			i++;
		}
		stack->stack[i] = tmp;
	}
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	rev_rotate(t_stack *stack)
{
	int i;
	int tmp;

	i = 0;
	if (stack->size > 0)
	{
		while (i < stack->size)
			i++;
		i--;
		tmp = stack->stack[i];
		while (i > 0)
		{
			stack->stack[i] = stack->stack[i - 1];
			i--;
		}
		stack->stack[i] = tmp;
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
}
