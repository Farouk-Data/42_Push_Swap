#include "checker_bonus.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_stack(t_stack *st)
{
	ft_swap(&(st->element[0].val), &(st->element[1].val));
	ft_swap(&(st->element[0].pos), &(st->element[1].pos));
}

void	ss_op(t_stack *st_a, t_stack *st_b)
{
	ft_swap(&(st_a->element[0].val), &(st_a->element[1].val));
	ft_swap(&(st_a->element[0].pos), &(st_a->element[1].pos));
	ft_swap(&(st_b->element[0].val), &(st_b->element[1].val));
	ft_swap(&(st_b->element[0].pos), &(st_b->element[1].pos));
}

void	rotate_stack(t_stack *st)
{
	int	i;

	i = 0;
	while (i < st->len - 1)
	{
		ft_swap(&(st->element[i].val), &(st->element[i + 1].val));
		ft_swap(&(st->element[i].pos), &(st->element[i + 1].pos));
		i++;
	}
}

void	rr_op(t_stack *st_a, t_stack *st_b)
{
	rotate_stack(st_a);
	rotate_stack(st_b);
}

void	reverse_rotate_stack(t_stack *st)
{
	int	i;

	i = st->len - 1;
	while (i > 0)
	{
		ft_swap(&(st->element[i].val), &(st->element[i - 1].val));
		ft_swap(&(st->element[i].pos), &(st->element[i - 1].pos));
		i--;
	}
}

void	rrr_op(t_stack *st_a, t_stack *st_b)
{
	reverse_rotate_stack(st_a);
	reverse_rotate_stack(st_b);
}

void push_to_b(t_stack *st_a, t_stack *st_b)
{
	int	i;

	i = st_b->len;
	while (i > 0)
	{
		st_b->element[i].val = st_b->element[i - 1].val;
		st_b->element[i].pos = st_b->element[i - 1].pos;
		i--;
	}
	st_b->element[0].val = st_a->element[0].val;
	st_b->element[0].pos = st_a->element[0].pos;
	while (i < st_a->len)
	{
		st_a->element[i].val = st_a->element[i + 1].val;
		st_a->element[i].pos = st_a->element[i + 1].pos;
		i++;
	}
	st_a->len--;
	st_b->len++;
}

void push_to_a(t_stack *st_a, t_stack *st_b)
{	
	int	i;

	i = st_a->len;
	while (i > 0)
	{
		st_a->element[i].val = st_a->element[i - 1].val;
		st_a->element[i].pos = st_a->element[i - 1].pos;
		i--;
	}
	st_a->element[0].val = st_b->element[0].val;
	st_a->element[0].pos = st_b->element[0].pos;
	while (i < st_b->len)
	{
		st_b->element[i].val = st_b->element[i + 1].val;
		st_b->element[i].pos = st_b->element[i + 1].pos;
		i++;
	}
	st_b->len--;
	st_a->len++;
}

