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

int	find_min(t_stack *stack)
{
	int	i;
	int	pos;
	int	min;

	i = 0;
	pos = 0;
	min = stack->element[0].val;
	while (i < stack->len)
	{
		if (min > stack->element[i].val)
		{
			min = stack->element[i].val;
			pos = i;
		}
		i++;
	}
	return (pos);
}

void		sort_three_numbers(t_stack *stack)
{
	if (stack->element[0].val > stack->element[1].val && stack->element[0].val < stack->element[2].val)
		swap_stack(stack, "sa\n");
	else if (stack->element[0].val > stack->element[1].val && stack->element[1].val > stack->element[2].val)
	{
		swap_stack(stack, "sa\n");
		reverse_rotate_stack(stack, "rra\n");
	}
	else if (stack->element[0].val > stack->element[2].val && stack->element[1].val < stack->element[2].val)
		rotate_stack(stack, "ra\n");
	else if (stack->element[0].val < stack->element[1].val && stack->element[0].val > stack->element[2].val)
	{
		reverse_rotate_stack(stack, "rra\n");
	}
	else if (stack->element[2].val > stack->element[0].val && stack->element[2].val < stack->element[1].val)
	{
		swap_stack(stack, "sa\n");
		rotate_stack(stack, "ra\n");
	}
}

void	sort_small_algo(t_stack *st_a, t_stack *st_b)
{
	int	pos;
	
	while (st_a->len > 3)
	{
		pos = find_min(st_a);
		if (pos == 0)
			push_to_b(st_a, st_b);
		else if (pos ==  1)
		{
			swap_stack(st_a, "sa\n");
			push_to_b(st_a, st_b);
		}
		else if (pos >= (st_a->len) / 2)
		{
			while (pos != 0)
			{
				reverse_rotate_stack(st_a, "rra\n");
				pos = find_min(st_a);
			}
			push_to_b(st_a, st_b);
		}
		else if(pos < (st_a->len) / 2)
		{
			while (pos != 0)
			{
				rotate_stack(st_a, "ra\n");
				pos = find_min(st_a);
			}
			push_to_b(st_a, st_b);
		}
	}
	sort_three_numbers(st_a);
	while (st_b->len)
		push_to_a(st_a, st_b);
}