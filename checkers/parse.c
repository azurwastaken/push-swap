/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:10:44 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/12/07 12:10:45 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static void	is_valid_space(int *size, int *i, int *j, char **input)
{
	*size = *size + 1;
	while (is_space(input[*i][*j]) && input[*i][*j] != '\0')
		*j = *j + 1;
	*size = input[*i][*j] == '\0' ? *size - 1 : *size;
}

int			is_valid(char **input)
{
	int i;
	int j;
	int size;

	i = 0;
	size = 0;
	while (input[i] && input[0][0] != 0)
	{
		j = 0;
		while (is_space(input[i][j]) && input[i][j] != '\0')
			j++;
		while (input[i][j] != '\0')
		{
			if (is_space(input[i][j]))
				is_valid_space(&size, &i, &j, input);
			if (!is_int(input[i][j])
				&& !is_space(input[i][j]) && input[i][j] != '\0')
				return (-1);
			j = input[i][j] != '\0' ? j + 1 : j;
		}
		size++;
		i++;
	}
	return (size);
}

int			init_stack(t_stack *a, t_stack *b, int size)
{
	if (!(a->stack = (int *)malloc(sizeof(int) * (size))))
		return (-1);
	if (!(b->stack = (int *)malloc(sizeof(int) * (size))))
		return (-1);
	a->size_max = size;
	b->size_max = size;
	a->size = 0;
	b->size = 0;
	return (0);
}

static int	isvldstr(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!is_num(str[i]))
		return (0);
	while (str[i] == '0')
	{
		j++;
		i++;
	}
	while (is_num(str[i]))
		i++;
	if ((str[i] != '\t' && str[i] != ' ' && str[i] != '\0') || i - j > 11)
		return (0);
	return (1);
}

int			fill_stack(char **input, t_stack *a)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j] != '\0')
		{
			if (!isvldstr(&input[i][j]) || is_valid_int(ft_atol(&input[i][j])))
				return (-1);
			a->stack[k++] = (int)ft_atol(&input[i][j]);
			while (is_space(input[i][j]) && input[i][j] != '\0')
				j++;
			while (is_int(input[i][j]) && input[i][j] != '\0')
				j++;
			while (is_space(input[i][j]) && input[i][j] != '\0')
				j++;
		}
		i++;
	}
	a->size = k;
	return (0);
}
