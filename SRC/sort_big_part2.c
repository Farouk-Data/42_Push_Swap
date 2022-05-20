#include "push_swap.h"

void	get_chunk2(t_stack *st_a, t_stack *st_b, int chunk)
{
	while (find_number(st_a, chunk))
	{
		if (st_a->element[0].pos < chunk)
		{
			push_to_b(st_a, st_b);
			printf("pos = %d here\n", st_b->element[0].pos);
			if (st_b->element[0].pos < (chunk - ((st_a->size/2) / 10)))
			{
				printf("pos = %d was here\n", st_a->element[0].pos);
				if (st_a->element[0].pos > chunk)
					rr_op(st_a, st_b);
				else 
					rotate_stack(st_b, "rb\n");
			}
		}
		else
			rotate_stack(st_a, "ra\n");
	}
}

void	sort_big_algo2(t_stack *st_a, t_stack *st_b)
{
	int	max;
	int	chunk;

	index_stack(st_a);
	chunk = st_a->size / 10;
	while (chunk <= st_a->size)
	{
		get_chunk2(st_a, st_b, chunk);
		chunk += st_a->size/10;
	}
	while (st_b->len)
	{
		max = find_max(st_b);
		if (max == 0)
			push_to_a(st_a, st_b);
		else if (max == 1)
		{
			swap_stack(st_b, "sb\n");
			push_to_a(st_a, st_b);
		}
		else if (max >= st_b->len / 2)
		{
			while (max != 0)
			{
				reverse_rotate_stack(st_b, "rrb\n");
				max = find_max(st_b);
			}
			push_to_a(st_a, st_b);
		}
		else if (max < st_b->len / 2)
		{
			while (max != 0)
			{
				rotate_stack(st_b, "rb\n");
				max = find_max(st_b);
			}
			push_to_a(st_a, st_b);
		}
	}
}