/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:39:36 by fech-cha          #+#    #+#             */
/*   Updated: 2022/05/22 18:26:14 by fech-cha         ###   ########.fr       */
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
