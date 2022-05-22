/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:37:46 by fech-cha          #+#    #+#             */
/*   Updated: 2022/05/22 21:52:59 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_op(t_stack *st_a, t_stack *st_b)
{
	rotate_stack(st_a, NULL);
	rotate_stack(st_b, NULL);
	ft_printf("rr\n");
}

void	reverse_rotate_stack(t_stack *st, char *str)
{
	int	i;

	i = st->len - 1;
	while (i > 0)
	{
		ft_swap(&(st->element[i].val), &(st->element[i - 1].val));
		ft_swap(&(st->element[i].pos), &(st->element[i - 1].pos));
		i--;
	}
	if (str != NULL)
		ft_print(str);
}

void	rrr_op(t_stack *st_a, t_stack *st_b)
{
	reverse_rotate_stack(st_a, NULL);
	reverse_rotate_stack(st_b, NULL);
	ft_printf("rrr\n");
}

void	push_to_b(t_stack *st_a, t_stack *st_b)
{
	int	i;

	i = st_b->len;
	while (i > 0)
	{
		st_b->element[i].val = st_b->element[i - 1].val;
		st_b->element[i].pos = st_b->element[i - 1].pos;
		i--;
	}
	st_b->element[0].val = st_a->element[0].val;
	st_b->element[0].pos = st_a->element[0].pos;
	while (i < st_a->len)
	{
		st_a->element[i].val = st_a->element[i + 1].val;
		st_a->element[i].pos = st_a->element[i + 1].pos;
		i++;
	}
	st_a->len--;
	st_b->len++;
	ft_printf("pb\n");
}

void	push_to_a(t_stack *st_a, t_stack *st_b)
{	
	int	i;

	i = st_a->len;
	while (i > 0)
	{
		st_a->element[i].val = st_a->element[i - 1].val;
		st_a->element[i].pos = st_a->element[i - 1].pos;
		i--;
	}
	st_a->element[0].val = st_b->element[0].val;
	st_a->element[0].pos = st_b->element[0].pos;
	while (i < st_b->len)
	{
		st_b->element[i].val = st_b->element[i + 1].val;
		st_b->element[i].pos = st_b->element[i + 1].pos;
		i++;
	}
	st_b->len--;
	st_a->len++;
	ft_printf("pa\n");
}
