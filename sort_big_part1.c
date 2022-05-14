#include "push_swap.h"

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


//indexing an array from small to big
void	index_stack(t_stack *stack)
{
	stack->positions = (int *)malloc(stack->size * sizeof(int));
	if (stack->positions == NULL)
		return ;
	
}

// void	copy_stack(int *arr1, int *arr2, int size)
// {
// 	int	i;
// 	int	j;
	
// 	i = 0;
// 	j = 0;
// 	while (i < size && j < size)
// 	{
// 		arr1[i] = arr2[j];
// 		i++;
// 		j++;
// 	}
// }

// void	sort_big_algo1(t_stack *st_a, t_stack *st_b)
// {

// }