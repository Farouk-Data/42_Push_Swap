/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:37:46 by fech-cha          #+#    #+#             */
/*   Updated: 2022/05/22 22:14:30 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_number(t_stack *st_a, int chunk)
{
	int	i;

	i = 0;
	while (i < st_a->len)
	{
		if (st_a->element[i].pos < chunk)
			return (1);
		i++;
	}
	return (0);
}

void	get_chunk(t_stack *st_a, t_stack *st_b, int chunk)
{
	while (find_number(st_a, chunk))
	{
		if (st_a->element[0].pos < chunk)
		{
			push_to_b(st_a, st_b);
			if (st_b->element[0].pos < (chunk - ((st_a->size / 2) / 5)))
			{
				if (st_a->element[0].pos > chunk)
					rr_op(st_a, st_b);
				else
					rotate_stack(st_b, "rb\n");
			}
		}
		else
			rotate_stack(st_a, "ra\n");
	}
}

void	swap_push(t_stack *st_a, t_stack *st_b)
{
	swap_stack(st_b, "sb\n");
	push_to_a(st_a, st_b);
}

void	sort_b(t_stack *st_a, t_stack *st_b)
{
	int	max;

	while (st_b->len)
	{
		max = find_max(st_b);
		if (max == 0)
			push_to_a(st_a, st_b);
		else if (max == 1)
			swap_push(st_a, st_b);
		else
		{
			while (max != 0)
			{
				if (max >= st_b->len / 2)
					reverse_rotate_stack(st_b, "rrb\n");
				else if (max < st_b->len / 2)
					rotate_stack(st_b, "rb\n");
				if (max >= st_b->len / 2 || max < st_b->len / 2)
					max = find_max(st_b);
			}
			push_to_a(st_a, st_b);
		}
	}
}

void	sort_big_algo1(t_stack *st_a, t_stack *st_b)
{
	int	chunk;

	index_stack(st_a);
	chunk = st_a->size / 5;
	while (chunk <= st_a->size)
	{
		get_chunk(st_a, st_b, chunk);
		chunk += st_a->size / 5;
	}
	sort_b(st_a, st_b);
}
