/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:07:46 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/12/07 12:07:49 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_stack
{
	int			*stack;
	int			size;
	int			size_max;
}				t_stack;

int				is_int(int a);
int				is_num(int a);
int				is_valid_int(long nb);
int				is_space(char c);
void			ft_putstr(char const *s);
long			ft_atol(const char *str);
size_t			ft_strlen(const char *str);
int				ft_strcmp(const char *s1, const char *s2);

int				is_valid(char **input);
int				init_stack(t_stack *a, t_stack *b, int size);
int				fill_stack(char **input, t_stack *a);
int				*ft_tabcpy(t_stack *a);

void			swap(t_stack *stack);
void			ss(t_stack *a, t_stack *b);
void			push(t_stack *a, t_stack *b);
void			rotate(t_stack *stack);
void			rr(t_stack *a, t_stack *b);
void			rev_rotate(t_stack *stack);

int				ft_stack_issort(t_stack *stack);
void			do_print(t_stack *a, t_stack *b, char *todo);
int				get_min(t_stack *a);
int				stack_sort(t_stack *a, t_stack *b);
void			split(t_stack *a, t_stack *b, int med);
void			stack_to_top(t_stack *a, t_stack *b, int position, char type);
int				check_cycle(t_stack *stack, int med);
int				get_med(t_stack *stack);
int				ft_stack_issort(t_stack *stack);
void			do_print(t_stack *a, t_stack *b, char *todo);
int				get_min(t_stack *a);
int				get_max(t_stack *stack);
int				ft_stack_find(t_stack *stack, int to_find);

#endif
