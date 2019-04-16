/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:08:39 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/10 16:40:49 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int		ft_stack_issort(t_stack *stack)
{
	int i;

	if (stack == NULL)
		return (0);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	do_print(t_stack *a, t_stack *b, char *todo)
{
	if ((ft_strcmp(todo, "sa") == 0)
		|| (ft_strcmp(todo, "ss") == 0))
		swap(a);
	if ((ft_strcmp(todo, "sb") == 0)
		|| (ft_strcmp(todo, "ss") == 0))
		swap(b);
	if ((ft_strcmp(todo, "ra") == 0)
		|| (ft_strcmp(todo, "rr") == 0))
		rotate(a);
	if ((ft_strcmp(todo, "rb") == 0)
		|| (ft_strcmp(todo, "rr") == 0))
		rotate(b);
	if ((ft_strcmp(todo, "rra") == 0)
		|| (ft_strcmp(todo, "rrr") == 0))
		rev_rotate(a);
	if ((ft_strcmp(todo, "rrb") == 0)
		|| (ft_strcmp(todo, "rrr") == 0))
		rev_rotate(b);
	if (ft_strcmp(todo, "pa") == 0)
		push(b, a);
	if (ft_strcmp(todo, "pb") == 0)
		push(a, b);
	ft_putstr(todo);
	ft_putstr("\n");
}

int		get_min(t_stack *a)
{
	int i;
	int min;

	i = 1;
	min = 0;
	while (i < a->size)
	{
		if (a->stack[i] < a->stack[min])
			min = i;
		i++;
	}
	return (min);
}

int		get_max(t_stack *a)
{
	int i;
	int max;

	i = 1;
	max = 0;
	while (i < a->size)
	{
		if (a->stack[i] > a->stack[max])
			max = i;
		i++;
	}
	return (max);
}
