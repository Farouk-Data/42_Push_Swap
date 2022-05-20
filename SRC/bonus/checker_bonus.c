#include "checker_bonus.h"

void	ft_print_output(char *str)
{
	write(1, str, 3);
}

int main(int argc, char **argv)
{
	int		count;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*instruct;
	char	**args;
	int	check;

	if (argc > 1)
	{
		count = 0; 
		if ((args = read_args(argc, argv, &count)) == NULL)
		{
			ft_print_error();
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
			ft_print_error();
			return (0);
		}
		check = 1;
		instruct = get_next_line(0);
		while (instruct && check)
		{
			if (!(check = execute_instruct(instruct, stack_a, stack_b)))
				break;
			instruct = get_next_line(0);
		}
		if (check == 0)
			exit(1) ;
		check_stack(stack_a, stack_b);
	}
}