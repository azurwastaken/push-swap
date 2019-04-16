/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:08:06 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/12/07 12:08:08 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static void		threelen_sort(t_stack *a, t_stack *b)
{
	int			top;
	int			mid;
	int			bot;

	if (a == NULL || ft_stack_issort(a))
		return ;
	if (a->size == 2)
	{
		do_print(a, b, "sa");
		return ;
	}
	bot = a->stack[2];
	mid = a->stack[1];
	top = a->stack[0];
	if ((bot > top && top > mid) || (bot > mid && mid > top))
		do_print(a, b, "sa");
	else if ((bot < mid && top < bot) || (bot > mid && mid < top)
		|| (bot < mid && mid > top && bot < top))
		do_print(a, b, "rra");
	else if (top > mid && mid > bot)
		do_print(a, b, "ra");
	threelen_sort(a, b);
}

static void		sort(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		split(a, b, get_med(a));
	threelen_sort(a, b);
	while (!ft_stack_issort(a) || b->size != 0)
	{
		stack_to_top(a, b, get_max(b), 'b');
		do_print(a, b, "pa");
		if (a->size >= 2)
		{
			if (a->stack[0]
				> a->stack[1])
				do_print(a, b, "sa");
		}
	}
}

int				stack_sort(t_stack *a, t_stack *b)
{
	if (a == NULL || b == NULL || a->size == 0 || ft_stack_issort(a))
		return (1);
	if (a->size == 2)
		threelen_sort(a, b);
	else
		sort(a, b);
	return (0);
}

void			split(t_stack *a, t_stack *b, int med)
{
	while (check_cycle(a, med))
	{
		if (a->stack[0] > med)
			do_print(a, b, "ra");
		else
			do_print(a, b, "pb");
	}
}
