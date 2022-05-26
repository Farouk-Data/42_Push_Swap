/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:37:46 by fech-cha          #+#    #+#             */
/*   Updated: 2022/05/22 22:09:26 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
}

void	free_double(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->element);
	free(stack_b->element);
}

int	push_swap(char *args[], t_stack *stack_a, t_stack *stack_b)
{
	ft_bzero(stack_b);
	convert_args(args, stack_a);
	if (check_dup(stack_a))
	{
		ft_print_error();
		return (0);
	}
	if (a_is_sorted(stack_a, stack_a->size))
		return (0);
	else if (stack_a->size <= 3)
		sort_three_numbers(stack_a);
	else if (stack_a->size >= 4 && stack_a->size <= 10)
		sort_small_algo(stack_a, stack_b);
	else if (stack_a->size >= 11 && stack_a->size <= 100)
		sort_big_algo1(stack_a, stack_b);
	else if (stack_a->size > 100 && stack_a->size <= 500)
		sort_big_algo2(stack_a, stack_b);
	return (1);
}

int	main(int argc, char *argv[])
{
	int		count;
	char	**args;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc > 1)
	{
		count = 0;
		args = read_args(argc, argv, &count);
		if (args == NULL)
			return (ft_print_error(), 0);
		stack_a.element = (t_node *)malloc(sizeof(t_node) * count);
		stack_a.size = count;
		stack_a.len = count;
		stack_b.element = (t_node *)malloc(sizeof(t_node) * count);
		stack_b.size = count;
		stack_b.len = 0;
		if (stack_a.element == NULL || stack_b.element == NULL)
			free_double(&stack_a, &stack_b);
		push_swap(args, &stack_a, &stack_b);
		free_double(&stack_a, &stack_b);
		return (0);
	}
	return (0);
}
