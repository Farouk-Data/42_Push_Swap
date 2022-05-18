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
	ft_swap(&(st->element[0].val), &(st->element[1].val));
	ft_swap(&(st->element[0].pos), &(st->element[1].pos));
	ft_print(str);
}

void	ss_op(t_stack *st_a, t_stack *st_b)
{
	ft_swap(&(st_a->element[0].val), &(st_a->element[1].val));
	ft_swap(&(st_a->element[0].pos), &(st_a->element[1].pos));
	ft_swap(&(st_b->element[0].val), &(st_b->element[1].val));
	ft_printf("ss\n");
}

void	rotate_stack(t_stack *st, char *str)
{
	int	i;

	i = 0;
	while (i < st->size - 1)
	{
		ft_swap(&(st->element[i].val), &(st->element[i + 1].val));
		ft_swap(&(st->element[i].pos), &(st->element[i + 1].pos));
		i++;
	}
	if (str != NULL)
		ft_print(str);
}

void	rr_op(t_stack *st_a, t_stack *st_b)
{
	rotate_stack(st_a, NULL);
	rotate_stack(st_b, NULL);
	ft_printf("rr\n");
}

void	reverse_rotate_stack(t_stack *st, char *str)
{
	int	i;

	i = st->size - 1;
	while (i > 0)
	{
		ft_swap(&(st->element[i].val), &(st->element[i - 1].val));
		ft_swap(&(st->element[i].pos), &(st->element[i - 1].pos));
		i--;
	}
	if (str != NULL)
		ft_print(str);
}

void	rrr_op(t_stack *st_a, t_stack *st_b)
{
	reverse_rotate_stack(st_a, NULL);
	reverse_rotate_stack(st_a, NULL);
	ft_printf("rrr\n");
}

// void push_to_b(t_stack *st_a, t_stack *st_b)
// {
// 	if (st_b->len > 0)
// 		st_b->id--;
// 	if (st_a->id < st_a->size && st_b->id >= 0)
// 	{
// 		st_b->arr[st_b->id] = st_a->arr[st_a->id];
// 		if (st_a->id != st_a->size)
// 			st_a->id++;
// 		st_b->len++;
// 		ft_printf("pb\n");
// 	}
// }

// void push_to_a(t_stack *st_a, t_stack *st_b)
// {	
// 	if (st_a->id >= 0 && st_b->id <= st_b->size - 1 && st_b->id >= 0)
// 	{
// 		st_a->id--;
// 		st_a->arr[st_a->id] = st_b->arr[st_b->id];
// 		ft_printf("pa\n");
// 		if (st_b->id != st_b->size )
// 			st_b->id++;
// 	}
// }

