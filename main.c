#include "push_swap.h"

int main(int argc, char **argv)
{
	int		count;
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		count = 0; 
		if ((args = read_args(argc, argv, &count)) == NULL)
		{
			ft_printf("Error\n");
			return (0);
		}
		stack_a = (t_stack *)malloc(sizeof(t_stack));
		stack_a->element= (t_node *)malloc(sizeof(t_node) * count);
		stack_a->size = count;
		stack_a->len = count;
		stack_b = (t_stack *)malloc(sizeof(t_stack));
		stack_b->element = (t_node *)malloc(sizeof(t_node) * count);
		stack_b->size = count;
		stack_b->len = 0;
		ft_bzero(stack_b);
		convert_args(args, stack_a);
		if (check_dup(stack_a))
		{
			ft_printf("Error\n");
			return (0);
		}
		
		if (A_is_sorted(stack_a, stack_a->size))
		  	return (1);
		push_to_b(stack_a, stack_b);
		for (int i = 0; i < stack_a->len; i++)
			printf("%d ", stack_a->element[i].val);
		printf("\n");

		swap_stack(stack_a, "sa\n");
		for (int i = 0; i < stack_a->len; i++)
			printf("%d ", stack_a->element[i].val);
		printf("\n");

		push_to_b(stack_a, stack_b);
		for (int i = 0; i < stack_a->len; i++)
			printf("%d ", stack_a->element[i].val);
		printf("\n");

		swap_stack(stack_a, "sa\n");
		for (int i = 0; i < stack_a->len; i++)
			printf("%d ", stack_a->element[i].val);
		printf("\n");

		rotate_stack(stack_a, "ra\n");
		for (int i = 0; i < stack_a->len; i++)
			printf("%d ", stack_a->element[i].val);
		printf("\n");

		push_to_a(stack_a, stack_b);
		for (int i = 0; i < stack_a->len; i++)
			printf("%d ", stack_a->element[i].val);
		printf("\n");
		
		push_to_a(stack_a, stack_b);
		for (int i = 0; i < stack_a->len; i++)
			printf("%d ", stack_a->element[i].val);
		printf("\n");

		// else if (stack_a->size == 3)
		//  	sort_three_numbers(stack_a);
		// else if (stack_a->size >= 4 && stack_a->size <= 10)
		// 	sort_small_algo(stack_a, stack_b);
		// else if (stack_a->size >= 11 && stack_a->size <= 100)
		// 	sort_big_algo1(stack_a, stack_b);
		// else if (stack_a->size > 100 && stack_a->size <= 500)
		// 	sort_big_algo2(stack_a, stack_b);
		// for (int i = 0; i < stack_a->size; i++)
		// 	printf("%d ", stack_a->element[i].val);
		// printf("\n");
	}
	return (0);
}