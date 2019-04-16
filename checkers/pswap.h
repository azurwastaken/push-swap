/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:10:51 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/12/07 12:10:52 by mcaseaux         ###   ########.fr       */
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

int				ft_puterror(t_stack *a, t_stack *b, int c);

int				is_int(int a);
int				is_num(int a);
int				is_valid_int(long nb);
int				is_space(char c);
void			ft_putstr(char const *s);
long			ft_atol(const char *str);
size_t			ft_strlen(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strnew(size_t size);
void			ft_bzero(void *s, size_t n);
char			*ft_strncat(char *s1, const char *s2, size_t nb);
char			*ft_strcpy(char *dest, const char *src);
void			ft_strdel(char **lacrim);
void			*ft_memset(void *b, int c, size_t len);

int				is_valid(char **input);
int				init_stack(t_stack *a, t_stack *b, int size);
int				fill_stack(char **input, t_stack *a);
int				*ft_tabcpy(t_stack *a);

void			swap(t_stack *stack);
void			ss(t_stack *a, t_stack *b);
void			push(t_stack *a, t_stack *b);
void			rotate(t_stack *stack);
void			rr(t_stack *a, t_stack *b);
void			rrr(t_stack *a, t_stack *b);
void			rev_rotate(t_stack *stack);

int				ft_stack_issort(t_stack *stack);
int				do_print(t_stack *a, t_stack *b, char *todo);
int				get_min(t_stack *a);
int				stack_sort(t_stack *a, t_stack *b);
void			split(t_stack *a, t_stack *b, int med);
void			stack_to_top(t_stack *a, t_stack *b, int position, char type);
int				check_cycle(t_stack *stack, int med);
int				get_med(t_stack *stack);
int				ft_stack_issort(t_stack *stack);
int				get_max(t_stack *stack);
int				ft_stack_find(t_stack *stack, int to_find);
void			ft_check(t_stack *a, t_stack *b);

#endif
