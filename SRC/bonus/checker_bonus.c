/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:39:36 by fech-cha          #+#    #+#             */
/*   Updated: 2022/05/22 16:18:40 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_print_output(char *str)
{
	write(1, str, 3);
}

void	free_double(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->element);
	free(stack_b->element);
}

int	checking(t_stack *stack_a, t_stack *stack_b, char **args)
{
	int		check;
	char	*instruct;

	ft_bzero(stack_b);
	convert_args(args, stack_a);
	if (check_dup(stack_a))
		return (ft_print_error(), (1));
	check = 1;
	instruct = get_next_line(0);
	while (instruct && check)
	{
		check = execute_instruct(instruct, stack_a, stack_b);
		free(instruct);
		if (!check)
			break ;
		instruct = get_next_line(0);
	}
	if (check == 0)
	{
		free_double(stack_a, stack_b);
		free(instruct);
		exit(1);
	}
	check_stack(stack_a, stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	int		count;
	t_stack	stack_a;
	t_stack	stack_b;
	char	**args;

	if (argc > 1)
	{
		count = 0;
		args = read_args(argc, argv, &count);
		if (args == NULL)
			return (ft_print_error(), (0));
		stack_a.element = (t_node *)malloc(sizeof(t_node) * count);
		stack_b.element = (t_node *)malloc(sizeof(t_node) * count);
		if (stack_a.element == NULL || stack_b.element == NULL)
			return (free_double(&stack_a, &stack_b), 0);
		stack_a.size = count;
		stack_a.len = count;
		stack_b.size = count;
		stack_b.len = 0;
		return (checking(&stack_a, &stack_b, args));
	}
}
