/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:39:36 by fech-cha          #+#    #+#             */
/*   Updated: 2022/05/21 22:39:42 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

int	execute_instruct2(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(str,"sa\n") == 0)
		swap_stack(stack_a);
	else if (ft_strcmp(str,"sb\n") == 0)
		swap_stack(stack_b);
	else if (ft_strcmp(str,"ss\n") == 0)
		ss_op(stack_a, stack_b);
	else if (ft_strcmp(str,"ra\n") == 0)
		rotate_stack(stack_a);
	else if (ft_strcmp(str,"rb\n") == 0)
		rotate_stack(stack_b);
	else if (ft_strcmp(str,"rr\n") == 0)
		rr_op(stack_a, stack_b);
	else if (ft_strcmp(str,"rra\n") == 0)
		reverse_rotate_stack(stack_a);
	else
		return (0);
	return (1);
}

int	execute_instruct(char *str, t_stack *stack_a, t_stack *stack_b)
{
	int	check;

	check = 1;
	if (execute_instruct2(str, stack_a, stack_b))
		return (check);
	else if (ft_strcmp(str,"rrb\n") == 0)
		reverse_rotate_stack(stack_b);
	else if (ft_strcmp(str,"rrr\n") == 0)
		rrr_op(stack_a, stack_b);
	else if (ft_strcmp(str,"pb\n") == 0)
		push_to_b(stack_a, stack_b);
	else if (ft_strcmp(str,"pa\n") == 0)
		push_to_a(stack_a, stack_b);
	else
	{
		check = 0 ;
		ft_print_error();
	}
	return (check);
}

void	check_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (A_is_sorted(stack_a, stack_a->size) && stack_b->len == 0)
		ft_print_output("OK\n");
	else 
		ft_print_output("KO\n");
}