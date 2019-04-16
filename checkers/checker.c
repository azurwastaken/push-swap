/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:09:14 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/12/07 12:09:17 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"
#include "get_next_line.h"

int		instruction_isvalid(char *tested)
{
	int			i;
	static char	*instruct[12] = { "sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr", 0 };

	i = 0;
	while (instruct[i] != NULL)
	{
		if (ft_strcmp(tested, instruct[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		ft_stack_issort(t_stack *stack)
{
	int i;

	i = 1;
	while (i < stack->size)
	{
		if (!(stack->stack[i - 1] < stack->stack[i]))
			return (0);
		i++;
	}
	return (1);
}

int		do_print(t_stack *a, t_stack *b, char *todo)
{
	if (!instruction_isvalid(todo))
		return (ft_puterror(a, b, 3));
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
	return (1);
}

void	ft_check(t_stack *a, t_stack *b)
{
	char	*todo;
	int		error;

	error = 0;
	while (get_next_line(0, &todo))
	{
		error = do_print(a, b, todo);
		free(todo);
		if (error == 0)
			return ;
	}
	free(todo);
	if (ft_stack_issort(a) && b->size == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
