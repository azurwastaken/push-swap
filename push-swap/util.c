/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:08:30 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/12/07 12:08:32 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static void		echanger(int v[], int i, int j)
{
	int			temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

static void		trirapide(int v[], int gauche, int droit)
{
	int			i;
	int			dernier;

	if (gauche >= droit)
		return ;
	echanger(v, gauche, (gauche + droit) / 2);
	dernier = gauche;
	i = gauche + 1;
	while (i <= droit)
	{
		if (v[i] < v[gauche])
			echanger(v, ++dernier, i);
		i++;
	}
	echanger(v, gauche, dernier);
	trirapide(v, gauche, dernier - 1);
	trirapide(v, dernier + 1, droit);
}

static int		*quicksort(int *v, int i)
{
	trirapide(v, 0, i - 1);
	return (v);
}

int				check_cycle(t_stack *stack, int med)
{
	int			i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] < med)
			return (1);
		i++;
	}
	return (0);
}

int				get_med(t_stack *stack)
{
	static int	bol;
	int			i;
	int			*a;

	if (bol != 2)
	{
		bol = stack->size;
		if (bol >= 150)
			bol = 1;
		else
			bol = 0;
	}
	a = ft_tabcpy(stack);
	i = stack->size;
	a = quicksort(a, i);
	if (i > 7 && bol == 1)
		i = a[i / 7];
	else
		i = a[i / 2];
	free(a);
	return (i);
}
