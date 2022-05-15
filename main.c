#include "push_swap.h"

int main(int argc, char **argv)
{
	int	i;
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		i = 0; 
		stack_a = (t_stack *)malloc(sizeof(t_stack));
		stack_b = (t_stack *)malloc(sizeof(t_stack));
		if ((args = read_args(argc, argv)) == NULL)
		{
			ft_printf("Error\n");
			return (0);
		}
		convert_args(args, stack_a);
		if (check_dup(stack_a->arr, stack_a->size))
		{
			ft_printf("Error\n");
			return (0);
		}
		stack_a->id = 0;
		stack_a->len = stack_a->size;
		stack_b->size = stack_a->size;
		stack_b->len = 0;
		stack_b->arr = (int *)malloc(sizeof(int)*stack_b->size);
		ft_bzero(stack_b->arr, stack_b->size);
		stack_b->id = stack_b->size-1;

		if (A_is_sorted(stack_a->arr, stack_a->size))
		  	return (1);
		else if (stack_a->size == 3)
		 	sort_three_numbers(stack_a);
		else if (stack_a->size >= 4 && stack_a->size <= 10)
			sort_small_algo(stack_a, stack_b);
		else if (stack_a->size >= 11 && stack_a->size <= 100)
			sort_big_algo1(stack_a, stack_b);

		// for (int i = stack_a->id; i < stack_a->size; i++)
		// 	printf("%d ",stack_a->arr[i]);
		// printf("\n");
	}
	return (0);
}