// #include "push_swap.h"

// int	find_min(int *arr, int size, int index)
// {
// 	int	i;
// 	int	pos;
// 	int	min;

// 	i = index;
// 	pos = 0;
// 	min = arr[index];
// 	while (i < size)
// 	{
// 		if (min > arr[i])
// 		{
// 			min = arr[i];
// 			pos = i;
// 		}
// 		i++;
// 	}
// 	return (pos);
// }

// void		sort_three_numbers(t_stack *stack)
// {
// 	if (stack->arr[stack->id] > stack->arr[stack->id+1] && stack->arr[stack->id] < stack->arr[stack->id+2])
// 		swap_stack(stack, "sa\n");
// 	else if (stack->arr[stack->id] > stack->arr[stack->id+1] && stack->arr[stack->id+1] > stack->arr[stack->id+2])
// 	{
// 		swap_stack(stack, "sa\n");
// 		reverse_rotate_stack(stack, "rra\n");
// 	}
// 	else if (stack->arr[stack->id] > stack->arr[stack->id+2] && stack->arr[stack->id+1] < stack->arr[stack->id+2])
// 		rotate_stack(stack, "ra\n");
// 	else if (stack->arr[stack->id] < stack->arr[stack->id+1] && stack->arr[stack->id] > stack->arr[stack->id+2])
// 	{
// 		reverse_rotate_stack(stack, "rra\n");
// 	}
// 	else if (stack->arr[stack->id+2] > stack->arr[stack->id] && stack->arr[stack->id+2] < stack->arr[stack->id+1])
// 	{
// 		swap_stack(stack, "sa\n");
// 		rotate_stack(stack, "ra\n");
// 	}
// }

// void	sort_small_algo(t_stack *st_a, t_stack *st_b)
// {
// 	int	pos;
	
// 	while (st_a->id < st_a->size - 3)
// 	{
// 		pos = find_min(st_a->arr, st_a->size, st_a->id);
// 		if (pos == 0)
// 			push_to_b(st_a, st_b);
// 		else if (pos ==  1)
// 		{
// 			swap_stack(st_a, "sa\n");
// 			push_to_b(st_a, st_b);
// 		}
// 		else if (pos >= (st_a->size - 1) / 2)
// 		{
// 			while (pos != 0)
// 			{
// 				reverse_rotate_stack(st_a, "rra\n");
// 				pos = find_min(st_a->arr,st_a->size, st_a->id);
// 			}
// 			push_to_b(st_a, st_b);
// 		}
// 		else if(pos < (st_a->size - 1) / 2)
// 		{
// 			while (pos != 0)
// 			{
// 				rotate_stack(st_a, "ra\n");
// 				pos = find_min(st_a->arr,st_a->size, st_a->id);
// 			}
// 			push_to_b(st_a, st_b);
// 		}
// 	}
// 	sort_three_numbers(st_a);
// 	while (st_b->id < st_b->size)
// 		push_to_a(st_a, st_b);
// }