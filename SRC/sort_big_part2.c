/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:37:46 by fech-cha          #+#    #+#             */
/*   Updated: 2022/05/21 22:37:49 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

#define DIV 10

void	get_chunk2(t_stack *st_a, t_stack *st_b, int chunk)
{
	while (find_number(st_a, chunk))
	{
		if (st_a->element[0].pos < chunk)
		{
			push_to_b(st_a, st_b);
			if (st_b->element[0].pos < (chunk - ((st_a->size/2) / DIV)))
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

void	sort_big_algo2(t_stack *st_a, t_stack *st_b)
{
	int	chunk;

	index_stack(st_a);
	chunk = st_a->size / DIV;
	while (chunk <= st_a->size)
	{
		get_chunk2(st_a, st_b, chunk);
		chunk += st_a->size/DIV;
	}
	sort_b(st_a, st_b);
}
