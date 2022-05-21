/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:37:46 by fech-cha          #+#    #+#             */
/*   Updated: 2022/05/21 22:37:49 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_strchr(char *str, int c)
{
	while (1)
	{
		if (*str == c)
			return (0);
		else if (*str == '\0')
			return (1);
		str++;
	}
	return (0);
}

void	ft_bzero(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		stack->element[i].val = 0;
		stack->element[i].pos = 0;
		i++;
	}
}

int	check_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 32 && str[i] <= 126)
			return (1);
		i++;
	}
	return (0);
}	

int	check_arg(char *str)
{
	if (*str == '-' && *(str + 1) == '0' && ft_strlen(str) == 2)
		return (1);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

char	**count_check(char	**arr_arg, int *count)
{
	int	i;

	i = 0;
	while (arr_arg[i] != NULL)
	{
		if (ft_atoi(arr_arg[i]) > INT_MAX || ft_atoi(arr_arg[i]) < INT_MIN)
			return (NULL);
		if (ft_atoi(arr_arg[i]) == 0 && check_arg(arr_arg[i]) == 0)
			return (NULL);
		*count = *count + 1;
		i++;
	}
	return (arr_arg);
}

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

int check_dup(t_stack *stack)
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

int	A_is_sorted(t_stack *stack, int size)
{
	if (size == 1 || size == 0)
		return (1);
	if (stack->element[size - 1].val < stack->element[size - 2].val)
		return (0);
	return A_is_sorted(stack, size - 1);
}