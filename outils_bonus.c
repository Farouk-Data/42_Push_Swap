#include "checker_bonus.h"

void	ft_print_error(void)
{
	write(2, "Error\n", 6);

}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	execute_instruct(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (strcmp(str,"sa\n") == 0)
		swap_stack(stack_a);
	else if (strcmp(str,"sb\n") == 0)
		swap_stack(stack_b);
	else if (strcmp(str,"ss\n") == 0)
		ss_op(stack_a, stack_b);
	else if (strcmp(str,"ra\n") == 0)
		rotate_stack(stack_a);
	else if (strcmp(str,"rb\n") == 0)
		rotate_stack(stack_b);
	else if (strcmp(str,"rr\n") == 0)
		rr_op(stack_a, stack_b);
	else if (strcmp(str,"rra\n") == 0)
		reverse_rotate_stack(stack_a);
	else if (strcmp(str,"rrb\n") == 0)
		reverse_rotate_stack(stack_b);
	else if (strcmp(str,"rrr\n") == 0)
		rrr_op(stack_a, stack_b);
	else
	{
		ft_print_error();
		return ;
	}
}