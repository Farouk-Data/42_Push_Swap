#include "push_swap.h"

//modify
int find_max(int *arr, int size, int index)
{
	int	i;
	int	max;
	int	pos;

	i = index;
	pos = 0;
	max = arr[i];
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

void	bubble_sort(int *arr, int size)
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
			if (arr[j] > arr[j + 1])
			{
				ft_swap(&arr[j], &arr[j + 1]);
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
		st_tmp->arr[i] = st_a->arr[i];
		i++;
	}
}

void	index_stack(t_stack *st_a)
{
	int		i;
	int		j;
	t_stack	*st_tmp;

	st_tmp = (t_stack *)malloc(sizeof(t_stack));
	st_tmp->arr = (int *)malloc(sizeof(int) * st_a->size);
	st_a->index = (int *)malloc(sizeof(int) * st_a->size);
	copy_stack(st_a, st_tmp);
	bubble_sort(st_tmp->arr, st_a->size);
	i = 0;
	while (i < st_a->size)
	{
		j = 0;
		while (j < st_a->size)
		{
			if (st_a->arr[i] == st_tmp->arr[j])
				st_a->index[i] = j;
			j++;
		}
		i++;
	}
	//free tmp
}

int	find_number(t_stack *st_a, int hold, int index)
{
	int	i;
	int	check;

	i = index;
	while (i < st_a->size)
	{
		if (st_a->index[i] < hold)
			return (1);
		i++;
	}
	return (0);
}
void	get_chunk(t_stack *st_a, t_stack *st_b, int hold)
{
	while (find_number(st_a, hold, st_a->id))
	{
		if (st_a->index[st_a->id] < hold)
		{
			push_to_b(st_a, st_b);
			if (st_a->index[st_a->id - 1] < (hold - ((st_a->size/2) / 5)))
			{
				if (st_a->index[st_a->id] > hold)
					rr_op(st_a, st_b);
				else 
					rotate_stack(st_b, "rb\n");
			}
		}
		else
			rotate_stack(st_a, "ra\n");
	}
}

void	sort_big_algo1(t_stack *st_a, t_stack *st_b)
{
	int	i;
	int	max;
	int	hold;
	int	tmp;

	index_stack(st_a);
	hold = st_a->size / 5;
	while (hold <= st_a->size)
	{
		get_chunk(st_a, st_b, hold);
		hold += st_a->size/5;
	}
	//stack B
	int k = st_b->id;
	while (k < st_b->size)
	{
		printf("%d ", st_b->arr[k]);
		k++;
	}
	while (st_b->id < st_b->size)
	{
		max = find_max(st_b->arr, st_b->size, st_b->id);
		if (max == st_b->id)
			push_to_a(st_a, st_b);
		else if (max == st_b->id + 1)
		{
			swap_stack(st_b, "sb\n");
			push_to_a(st_a, st_b);
		}
		else if (max >= (st_b->size - 1) / 2)
		{
			tmp = st_b->id;
			while (max != 0)
			{
				reverse_rotate_stack(st_b, "rrb\n");
				max = find_max(st_b->arr, st_b->size, st_b->id);
			}
			push_to_a(st_a, st_b);
		}
		else if (max < (st_b->size - 1) / 2)
		{
			tmp = st_b->id;
			while (max != 0)
			{
				rotate_stack(st_b, "rb\n");
				max = find_max(st_b->arr, st_b->size, st_b->id);
			}
			push_to_a(st_a, st_b);
		}
	}
	printf("\n");
	int m = st_a->id;
	while (m < st_a->size)
	{
		printf("%d ", st_a->arr[m]);
		m++;
	}
}