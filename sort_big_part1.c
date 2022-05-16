#include "push_swap.h"

//modify
int find_max(int *arr, int size, int index)
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


void	sort_big_algo1(t_stack *st_a, t_stack *st_b)
{
	int	max;
	int	hold;

	index_stack(st_a);
	hold = st_a->id;
	while (st_a->id < st_a->size)
	{
		if (st_a->index[st_a->id] < 20)
		{
			if (st_a->id >= st_a->size - 1 / 2)
			{
				while (st_a->id != hold)
					reverse_rotate_stack(st_a, "rra\n");
				push_to_b(st_a, st_b);
				hold = st_a->id;
			}
			if (st_a->id < st_a->size - 1 / 2)
			{
				while (st_a->id != hold)
					rotate_stack(st_a, "ra\n");
				push_to_b(st_a, st_b);
				hold = st_a->id;
			}
		}
	}
	while (st_b->id < st_b->size)
	{
		max = find_max(st_b->arr, st_b->size, st_b->id);
	}
}