/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:37:46 by fech-cha          #+#    #+#             */
/*   Updated: 2022/05/22 22:29:43 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
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
	st_tmp->element = (t_node *)malloc(sizeof(t_node) * st_a->size);
	if (st_tmp->element == NULL || st_tmp == NULL)
		return ;
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
	free(st_tmp->element);
	free(st_tmp);
}
