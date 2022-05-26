/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:37:46 by fech-cha          #+#    #+#             */
/*   Updated: 2022/05/22 22:45:50 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sub_args(t_stack *st, int a, int b, int c)
{
	if (a > b && a < c)
		swap_stack(st, "sa\n");
	else if (a > b && b > c)
	{
		swap_stack(st, "sa\n");
		reverse_rotate_stack(st, "rra\n");
	}
	else if (a > c && b < c)
		rotate_stack(st, "ra\n");
	else if (a < b && a > c)
	{
		reverse_rotate_stack(st, "rra\n");
	}
	else if (c > a && c < b)
	{
		swap_stack(st, "sa\n");
		rotate_stack(st, "ra\n");
	}
}

void	sort_three_numbers(t_stack *st)
{
	int	a;
	int	b;
	int	c;

	a = st->element[0].val;
	b = st->element[1].val;
	c = st->element[2].val;
	if (st->size == 2 && a > b)
		swap_stack(st, "sa\n");
	else
		sub_args(st, a, b, c);
}

void	swap_push_b(t_stack *st_a, t_stack *st_b)
{
	swap_stack(st_a, "sa\n");
	push_to_b(st_a, st_b);
}

void	sort_a(t_stack *st_a, t_stack *st_b)
{
	int	pos;

	while (st_a->len > 3)
	{
		pos = find_min(st_a);
		if (pos == 0)
			push_to_b(st_a, st_b);
		else if (pos == 1)
			swap_push_b(st_a, st_b);
		else
		{
			while (pos != 0)
			{
				if (pos >= (st_a->len / 2))
					reverse_rotate_stack(st_a, "rra\n");
				else if (pos < (st_a->len) / 2)
					rotate_stack(st_a, "ra\n");
				pos = find_min(st_a);
			}
			push_to_b(st_a, st_b);
		}
	}
}

void	sort_small_algo(t_stack *st_a, t_stack *st_b)
{
	sort_a(st_a, st_b);
	sort_three_numbers(st_a);
	while (st_b->len)
		push_to_a(st_a, st_b);
}
