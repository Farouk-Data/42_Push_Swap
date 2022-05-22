/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:39:36 by fech-cha          #+#    #+#             */
/*   Updated: 2022/05/22 18:23:54 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	**read_args(int argc, char **argv, int *count)
{
	int		i;
	char	*args;
	char	**arr_arg;

	i = 1;
	args = NULL;
	arr_arg = NULL;
	while (i < argc)
	{
		if (!check_empty(argv[i]))
		{
			free(args);
			return (arr_arg);
		}
		args = ft_strjoin(args, argv[i]);
		args = ft_strjoin(args, " ");
		i++;
	}
	arr_arg = ft_split(args, ' ');
	free(args);
	return (count_check(arr_arg, count));
}

void	convert_args(char **args, t_stack *stack)
{
	int	i;

	if (stack == NULL)
		return ;
	i = 0;
	while (args[i] != NULL)
	{
		stack->element[i].val = ft_atoi(args[i]);
		i++;
	}
	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	check_dup(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;
	int	duplicate;

	i = 0;
	duplicate = NOT_FOUND;
	while (i < stack->size)
	{
		j = i;
		tmp = stack->element[i].val;
		while (j < stack->size - 1)
		{
			if (tmp == stack->element[j + 1].val)
			{
				duplicate = FOUND;
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	a_is_sorted(t_stack *stack, int size)
{
	if (size == 1 || size == 0)
		return (1);
	if (stack->element[size - 1].val < stack->element[size - 2].val)
		return (0);
	return (a_is_sorted(stack, size - 1));
}
