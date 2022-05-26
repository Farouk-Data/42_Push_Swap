/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:45:54 by fech-cha          #+#    #+#             */
/*   Updated: 2022/05/22 02:55:28 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define FOUND 0
# define NOT_FOUND 1
# define IN 1 
# define OUT 0
# define BUFFER_SIZE 100

typedef struct s_node
{
	int	val;
	int	pos;
}	t_node;

typedef struct s_stack
{
	t_node	*element;
	int		size;
	int		len;
}	t_stack;

void		free_double(t_stack *stack_a, t_stack *stack_b);
void		init_param(int *i, char **args, char ***arr_arg);
int			check_arg(char *str);
void		swap_push(t_stack *st_a, t_stack *st_b);
void		bubble_sort(t_stack *stack);
void		ft_print_error(void);
int			find_max(t_stack *stack);
void		copy_stack(t_stack *st_a, t_stack *st_tmp);
void		index_stack(t_stack *st_a);
int			find_number(t_stack *st_a, int chunk);
void		get_chunk(t_stack *st_a, t_stack *st_b, int chunk);
void		get_chunk2(t_stack *st_a, t_stack *st_b, int chunk);
void		ft_bzero(t_stack *stack);
void		ft_print(char *str);
int			ft_printf(const char *str, ...);
int			ft_putchar(char c);
int			ft_putnbr(int nb);
int			ft_putstr(char *str);
int			ft_print_unsigned(unsigned int n);
int			ft_print_lower_hexa(long unsigned int nb);
int			ft_print_upper_hexa(unsigned int nb);
int			ft_print_addrs(long unsigned int nb);
size_t		ft_strlen(const char *s);
void		convert_args(char **args, t_stack *stack);
char		**read_args(int argc, char **argv, int *count);
long int	ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *s);
int			check_dup(t_stack *stack);
int			check_empty(char *str);
void		ft_swap(int *a, int *b);
void		swap_stack(t_stack *st, char *str);
void		ss_op(t_stack *st_a, t_stack *st_b);
void		rotate_stack(t_stack *st, char *str);
void		rr_op(t_stack *st_a, t_stack *st_b);
void		reverse_rotate_stack(t_stack *st, char *str);
void		rrr_op(t_stack *st_a, t_stack *st_b);
void		push_to_b(t_stack *st_a, t_stack *st_b);
void		push_to_a(t_stack *st_a, t_stack *st_b);
int			find_min(t_stack *stack);
int			a_is_sorted(t_stack *stack, int size);
void		sort_three_numbers(t_stack *stack);
void		sort_small_algo(t_stack *st_a, t_stack *st_b);
void		sort_big_algo1(t_stack *st_a, t_stack *st_b);
void		sort_big_algo2(t_stack *st_a, t_stack *st_b);
void		sort_b(t_stack *st_a, t_stack *st_b);
void		swap_push(t_stack *st_a, t_stack *st_b);
#endif
