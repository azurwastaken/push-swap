/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_top_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:08:18 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/12/07 12:08:22 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static void		handle_action(t_stack *a, t_stack *b, int *gap,
char type)
{
	int			i;

	i = 0;
	if (gap[0] < gap[1])
	{
		while (i++ < gap[0])
		{
			if (type == 'a')
				do_print(a, b, "ra");
			else
				do_print(a, b, "rb");
		}
	}
	else
	{
		while (i++ <= gap[1])
		{
			if (type == 'a')
				do_print(a, b, "rra");
			else
				do_print(a, b, "rrb");
		}
	}
}

void			stack_to_top(t_stack *a, t_stack *b, int position, char type)
{
	int			gap[2];

	if ((a == NULL) || (b == NULL) || (position == 0))
		return ;
	gap[1] = type == 'a' ? (a->size - 1) - position : (b->size - 1) - position;
	gap[0] = position;
	handle_action(a, b, gap, type);
}
