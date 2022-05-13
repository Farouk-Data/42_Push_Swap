#include "push_swap.h"

void	ft_print(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_stack(t_stack *st, char *str)
{
	ft_swap(&(st->arr[st->id]), &(st->arr[st->id+1]));
	ft_print(str);
}

void	ss_op(t_stack *st_a, t_stack *st_b)
{
	ft_swap(&(st_a->arr[st_a->id]), &(st_a->arr[st_a->id+1]));
	ft_swap(&(st_b->arr[st_b->id]), &(st_b->arr[st_b->id+1]));
	ft_printf("ss\n");
}

void	rotate_stack(t_stack *st, char *str)
{
	int	i;

	i = st->id;
	while (i < st->size - 1)
	{
		ft_swap(&(st->arr[i]), &(st->arr[i + 1]));
		i++;
	}
	ft_print(str);
}

void	rr_op(t_stack *st_a, t_stack *st_b)
{
	int	i;
	int	j;

	i = st_a->id;
	j = st_b->id;
	while (i < st_a->size - 1 && j < st_b->size - 1)
	{
		ft_swap(&(st_a->arr[i]), &(st_a->arr[i + 1]));
		ft_swap(&(st_b->arr[j]), &(st_b->arr[j + 1]));
		i++;
		j++;
	}
	ft_printf("rr\n");
}

void	reverse_rotate_stack(t_stack *st, char *str)
{
	int	i;

	i = st->size - 1;
	while (i > st->id)
	{
		ft_swap(&(st->arr[i]), &(st->arr[i - 1]));
		i--;
	}
	ft_print(str);
}

void	rrr_op(t_stack *st_a, t_stack *st_b)
{
	int	i;
	int	j;

	i = st_a->size - 1;
	j = st_b->size - 1;
	while (i != st_a->id && j != st_b->id)
	{
		ft_swap(&(st_a->arr[i]), &(st_a->arr[i - 1]));
		ft_swap(&(st_b->arr[j]), &(st_b->arr[j - 1]));
		i--;
		j--;
	}
	ft_printf("rrr\n");
}

void push_to_b(t_stack *st_a, t_stack *st_b)
{
	if (st_b->len > 0)
		st_b->id--;
	if (st_a->id < st_a->size && st_b->id >= 0)
	{
		st_b->arr[st_b->id] = st_a->arr[st_a->id];
		st_a->id++;
		st_b->len++;
		ft_printf("pb\n");
	}
}

void push_to_a(t_stack *st_a, t_stack *st_b)
{	
	if (st_a->id >= 0 && st_b->id <= st_b->size - 1)
	{
		st_a->id--;
		st_a->arr[st_a->id] = st_b->arr[st_b->id];
		ft_printf("pa\n");
		st_b->id++;
	}
}

