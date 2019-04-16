/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:36:26 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/10 15:37:03 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_is_doublon(t_stack *stack)
{
	int i;
	int j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (stack->stack[i] == stack->stack[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_puterror(t_stack *a, t_stack *b, int c)
{
	if (c == 0 || c == 2)
	{
		free(a->stack);
		free(b->stack);
	}
	if (c < 3)
	{
		free(a);
		free(b);
	}
	if (c > 0)
		ft_putstr("Error\n");
	return (0);
}

int	main(int ac, char **av)
{
	int		size;
	t_stack *a;
	t_stack *b;

	if (ac > 1)
	{
		if (!(a = malloc(sizeof(t_stack))))
			return (0);
		if (!(b = malloc(sizeof(t_stack))))
			return (0);
		size = is_valid(&av[1]);
		if (size <= 0)
			return (ft_puterror(a, b, 1));
		if (init_stack(a, b, size) < 0)
			return (ft_puterror(a, b, 1));
		if (fill_stack(&av[1], a) < 0)
			return (ft_puterror(a, b, 2));
		if (ft_is_doublon(a) > 0)
			return (ft_puterror(a, b, 2));
		stack_sort(a, b);
		return (ft_puterror(a, b, 0));
	}
	return (0);
}
