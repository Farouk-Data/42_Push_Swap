#include "push_swap.h"

void	ft_free(t_stack *stack_a)
{
	free(stack_a->arr);
	free(stack_a);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tpc;

	tpc = s;
	if (n == 0)
		return ;
	while (n)
	{
		*tpc = 0;
		tpc++;
		n--;
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

char	**read_args(int argc, char **argv)
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
			return (arr_arg);
		args = ft_strjoin(args, argv[i]);
		args = ft_strjoin(args, " ");
		i++;
	}
	arr_arg = ft_split(args, ' ');
	free(args);
	i = 0;
	while (arr_arg[i] != NULL)
	{
		if (ft_atoi(arr_arg[i]) >= INT_MAX || ft_atoi(arr_arg[i]) <= INT_MIN)
			return (NULL);
		if (ft_atoi(arr_arg[i]) == 0 && check_arg(arr_arg[i]) == 0)
			return (NULL);
		i++;
	}
	return (arr_arg);
}

void	convert_args(char **args, t_stack *stack)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	stack->size = i; 
	stack->arr = (int *)malloc(sizeof(int)*stack->size);
	i = 0;
	while (args[i] != NULL)
	{
		stack->arr[i] = ft_atoi(args[i]);
		i++;
	}
}

int check_dup(int *ar, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	duplicate;

	i = 0;
	duplicate = NOT_FOUND;
	while (i < size)
	{
		j = i;
		tmp = ar[i];
		while (j < size - 1)
		{
			if (tmp == ar[j + 1])
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

int	A_is_sorted(int	*arr, int size)
{
	if (size == 1 || size == 0)
		return (1);
	if (arr[size - 1] < arr[size - 2])
		return (0);
	return A_is_sorted(arr, size - 1);
}