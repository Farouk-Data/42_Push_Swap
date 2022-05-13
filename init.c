#include "push_swap.h"

void	ft_init(int argc, t_stack *stack_a, t_stack *stack_b)
{
		stack_a = (t_stack *)malloc(sizeof(t_stack));
		stack_b = (t_stack *)malloc(sizeof(t_stack));
		stack_a->arr = (int *)malloc((argc - 1) * sizeof(int));
		stack_b->arr = (int *)malloc((argc - 1) * sizeof(int));
}