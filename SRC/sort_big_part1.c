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

int find_max(t_stack *stack)
{
	int	i;
	int	max;
	int	pos;

	i = 0;
	pos = 0;
	max = stack->element[0].val;
	while (i < stack->len)
	{
		if (max < stack->element[i].val)
		{
			max = stack->element[i].val;
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	bubble_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < stack->size - 1)
	{
		j = 0;
		swapped = FALSE;
		while (j < stack->size - i - 1)
		{
			if (stack->element[j].val > stack->element[j + 1].val)
			{
				ft_swap(&stack->element[j].val, &stack->element[j + 1].val);
				swapped = TRUE;
			}
			j++;
		}
		if (swapped == FALSE)
			break ;
		i++;
	}
}

void	copy_stack(t_stack *st_a, t_stack *st_tmp)
{
	int	i;
	
	i = 0;
	while (i < st_a->size)
	{
		st_tmp->element[i].val = st_a->element[i].val;
		i++;
	}
}

void	index_stack(t_stack *st_a)
{
	int		i;
	int		j;
	t_stack	*st_tmp;

	st_tmp = (t_stack *)malloc(sizeof(t_stack));
	st_tmp->element = (t_node *)malloc(sizeof(t_node)*st_a->size);
	st_tmp->size = st_a->size;
	copy_stack(st_a, st_tmp);
	bubble_sort(st_tmp);
	i = 0;
	while (i < st_a->size)
	{
		j = 0;
		while (j < st_a->size)
		{
			if (st_a->element[i].val == st_tmp->element[j].val)
				st_a->element[i].pos = j;
			j++;
		}
		i++;
	}
}

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
			if (st_b->element[0].pos < (chunk - ((st_a->size/2) / 5)))
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

void swap_push(t_stack *st_a, t_stack *st_b)
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
		chunk += st_a->size/5;
	}
	sort_b(st_a, st_b);
}