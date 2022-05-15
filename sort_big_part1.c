#include "push_swap.h"

//changing storing values
void	copy_stack(t_stack *stack)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < stack->size && j < stack->size)
	{
		stack->node[i].val = stack->arr[j];
		i++;
		j++;
	}
}

void	bubble_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		swapped = FALSE;
		while (j < size - i - 1)
		{
			if (stack->node[j].val > stack->node[j + 1].val)
			{
				ft_swap(&stack->node[j].val, &stack->node[j+1].val);
				swapped = TRUE;
			}
			j++;
		}
		if (swapped == FALSE)
			break ;
		i++;
	}
}

//modify
int find_max(t_stack *stack)
{
	int	i;
	int	max;
	int	pos;

	i = index;
	pos = 0;
	max = arr[index];
	while (i < size)
	{
		if (max < arr[i])
		{
			max = arr[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	copy_from_to_stack(t_stack *st1, t_stack *st2)
{
	int	i;

	i = 0;
	while (i < st1->size)
	{
		st2->node[i].val = st1->node[i].val;
		i++;
	}
}

//indexing an array from small to big
void	index_stack(t_stack *stack)
{
	int	i;
	int	j;
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	copy_stack(stack);
	copy_from_to_stack(stack, tmp);
	bubble_sort(tmp);
	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (tmp->node[i].val == stack->node[j].val)
				stack->node[j].pos = i;
			j++;
		}
		i++;
	}
}


void	sort_big_algo1(t_stack *st_a, t_stack *st_b)
{
	;
}